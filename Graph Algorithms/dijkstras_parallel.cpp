#include <mpi.h>

#include <bits/stdc++.h>

int infinity = INT_MAX;

using namespace std;

int find_min_node(int num_nodes,int distance[],bool finalized[]){
    int min_node = -1;
    int min_distance = infinity;
    for(int i=0;i<num_nodes;i++){
        if(finalized[i] == false && distance[i] <= min_distance){
            min_node = i;
            min_distance = distance[i];
        }
    }
    return min_node;
}

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);
    int total_processes;
    int process_rank;
    MPI_Comm_size( MPI_COMM_WORLD, &total_processes );
    MPI_Comm_rank( MPI_COMM_WORLD, &process_rank );
    MPI_Status status;

    int n,source;
    int *col_major = NULL;
    int *final_distance = NULL;
    if(process_rank == 0){
        int m;
        //n = 4;
        cin>>n; // number of nodes
        cin>>m; // number of edges
        cin>>source; // source vertex
        if(n%total_processes != 0){
            cout<<"number of vertices should be divisible by number of processes\n";
            MPI_Abort(MPI_COMM_WORLD, MPI_ERR_COUNT);  // end all processes as number of nodes is not divisible by number of processes.
        }
        final_distance = (int *)malloc(n * sizeof(int));
        int **adj_mat = (int **)malloc(n * sizeof(int *));  // n*n adjacency matrix
        for(int i=0; i<n; i++){ 
            adj_mat[i] = (int *)malloc(n * sizeof(int));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                    adj_mat[i][j] = 0;
                }
                else{
                    adj_mat[i][j] = infinity;
                }
            }
        }
        for(int i=0;i<m;i++){
            int src,dest,distance;
            cin>>src;
            cin>>dest;
            cin>>distance;
            adj_mat[src][dest] = distance;
        }
        //int adj_mat[4][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
        col_major = (int*) malloc(n * n * sizeof(int *));
        int ind=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                col_major[ind++] = adj_mat[i][j];
            }
        }

    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&source, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(n%total_processes != 0){
        cout<<"number of vertices should be divisible by number of processes\n";
        MPI_Abort(MPI_COMM_WORLD, MPI_ERR_COUNT);  // end all processes as number of nodes is not divisible by number of processes.
    }
    int cols_per_proc = (n/total_processes);
    int num_elements_per_proc = cols_per_proc*n;
    int *sub_array = (int *)malloc(num_elements_per_proc * sizeof(int));
    
    MPI_Scatter(col_major, num_elements_per_proc, MPI_INT, sub_array,num_elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);
    // cout<<"at process "<< process_rank<<" source "<<source<<"\n";
    // for(int i=0;i<num_elements_per_proc;i++){
    //     cout<<sub_array[i]<<" ";
    // }
    //cout<<"\n";
    int **sub_adj_mat = (int **)malloc(n * sizeof(int *));  // n*cols_per_proc sub-adjacency matrix
    for(int i=0; i<n; i++){ 
        sub_adj_mat[i] = (int *)malloc(cols_per_proc * sizeof(int));
    }
    int ind=0;
    for(int j=0;j<cols_per_proc;j++){
        for(int i=0;i<n;i++){
            sub_adj_mat[i][j] = sub_array[ind++];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<cols_per_proc;j++){
    //         cout<<sub_adj_mat[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }


    // dijkstra starts here

    int *distance = (int *)malloc(cols_per_proc * sizeof(int)); // stores shortest distance to nodes which this process handles
    bool *finalized = (bool *)malloc(cols_per_proc * sizeof(bool)); // stores if this node has been finalized

    // initialize distances
    for(int i=0;i<cols_per_proc;i++){
        finalized[i] = false;
        int actual_node = process_rank*cols_per_proc + i;
        if(actual_node == source){
            distance[i] = 0;
        }
        else{
            distance[i] = infinity;
        }
    }

    MPI_Barrier(MPI_COMM_WORLD); 	// Waits until all processors initialize distances

    for(int iter=0;iter<n;iter++){ // at each step one node is finalized
        int nd = find_min_node(cols_per_proc,distance,finalized);
        int actual_min_nd = -1;
        int min_distance = infinity;
        int local_min_node_info[2];
        int global_min_node_info[2];
        if(nd != -1){
            actual_min_nd = process_rank*cols_per_proc + nd;
            min_distance = distance[nd];
        }
        //cout<<"iter "<< iter <<"at process "<< process_rank<< " min node is "<<actual_min_nd << " and distance is "<<min_distance<<"\n";
        local_min_node_info[0] = min_distance;
        local_min_node_info[1] = actual_min_nd;
        MPI_Allreduce(local_min_node_info, global_min_node_info, 1, MPI_2INT, MPI_MINLOC, MPI_COMM_WORLD);

        int global_min_node_distance = global_min_node_info[0];
        int global_min_node = global_min_node_info[1];
        //cout<<"iter "<<iter<<" at process "<< process_rank<< " global min node is "<<global_min_node << " and distance is "<<global_min_node_distance<<"\n";
        if(global_min_node == local_min_node_info[1]){ // this node belongs to me
            int my_representation_of_node = global_min_node % cols_per_proc;
            finalized[my_representation_of_node] = true;
        }
        if(process_rank == 0){ // update final distance at process 0
            final_distance[global_min_node] = global_min_node_distance;
        }

        // update distances from source via this min_node
        for(int i=0;i<cols_per_proc;i++){
            if(sub_adj_mat[global_min_node][i] != infinity){ // if edge exists between min_node and given node
                int new_dist = global_min_node_distance + sub_adj_mat[global_min_node][i];
                int old_dist = distance[i];
                if(new_dist < old_dist){
                    distance[i] = new_dist;
                }
            }
        }
        // cout<<"iter "<<iter <<" update at process "<< process_rank<<"\n";
        // for(int i=0;i<cols_per_proc;i++){
        //     cout<<distance[i]<<" ";
        // }
        // cout<<"\n";
    }

    MPI_Barrier(MPI_COMM_WORLD); 	// Waits until all processors have finished their work

    if(process_rank == 0){
        for(int i=0;i<n;i++){
            cout<<final_distance[i]<<" ";
        }
        cout<<"\n";
    }

    MPI_Finalize();
    return 0;
}
