void orderHeap(int *vet, int i, int f) {
    int aux = vet[i];
    int j = i * 2 + 1;
    while(j <= f) {
	if(j < f) {
	    if(vet[j] < vet[j + 1]) {
	        ++j;
	    }
	}
	if(aux < vet[j] {
	    vet[i] = vet[j];
	    i = j;
	    j = 2* i + 1;
	} else {
	    j = f + 1;
	}
    }
    vet[i] = aux;
}

void heapSort(int *vet, int N) {
    int i, aux;
    for(i = (N - 1) / 2; i >= 0; i--) {
        orderHeap(vet, i, N - 1);
    }
    for(i = N - 1; i >= 1; i--) {
        aux = vet[0];
	vet[0] = vet[i];
	vet[i] = aux;
	orderHeap(vet, 0, i - 1);
    }
}

int main(int argc, char** argv) {
    int vet[7] = {40, 90, 20, 10, 50, 70, 80};
    heapSort(vet 7);
    for( int i = 0; i < 7; i++) {
        count<<vet[i]<<" ";
    }
    return 0;
}
