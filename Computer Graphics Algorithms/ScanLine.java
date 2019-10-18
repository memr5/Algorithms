package scanline;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;


//Updated code with mouse iterface
public class ScanLine extends JFrame{
    
    private int prevX;
    private int prevY;
    private int noOfVertices, count = 0;
    
    private ArrayList<Edge> edgeTable = new ArrayList<>();

    public void inputNoOfVertices() {
        System.out.println("Specify no. of vertices of polygon :-");
        Scanner scanner = new Scanner(System.in);
        noOfVertices = scanner.nextInt();
    }
    
    private MouseListener mouselistener=new MouseListener(){
        @Override
        public void mouseClicked(MouseEvent e) {
            
            Graphics g=getGraphics();
            
            int x=e.getXOnScreen();
            int y=e.getYOnScreen();
            
            if(count==0){
                prevX=x;
                prevY=y;
            }
            else{
                edgeTable.add(new Edge(prevX,prevY,x,y));
                g.drawLine(prevX,prevY,x,y);
                prevX=x;
                prevY=y;
            }
            
            count++;
            if(count==noOfVertices){
                edgeTable.add(new Edge(x, y, edgeTable.get(0).x1, edgeTable.get(0).y1));
                g.drawLine(x, y,edgeTable.get(0).x1, edgeTable.get(0).y1);
                DeleteListener();
                scanLine();
            }
            
        }

        @Override
        public void mousePressed(MouseEvent e) {
        }

        @Override
        public void mouseReleased(MouseEvent e) {
        }

        @Override
        public void mouseEntered(MouseEvent e) {
        }

        @Override
        public void mouseExited(MouseEvent e) {
        }
            
    };
            
    public void inputPolygon(){
        addMouseListener(mouselistener);
    }
    
    public void DeleteListener(){
        removeMouseListener(mouselistener);
    }
    
    private int getYmin(){
       
          int yMin=edgeTable.get(0).y1;
        for(Edge edge : edgeTable ){
            if(edge.y1 < yMin)
                yMin=edge.y1;
        }
        return yMin;
    }
    
    private int getYmax(){
        
        int yMax=edgeTable.get(0).y1;
        for(Edge edge : edgeTable ){
            if(edge.y1>yMax)
                yMax=edge.y1;
        }
        return yMax;
        
    }
    
    private boolean isActive(Edge edge,int currentY){
        
        if(edge.y1 < currentY && currentY <= edge.y2 || edge.y1 >= currentY && currentY >edge.y2 )
            return true;
        
        return false;
    }
    
    private ArrayList <Edge> updateActiveEdges(ArrayList<Edge> activeEdges,int y){
        
        for(Edge edge: edgeTable){
             
            if(isActive(edge,y)){
                if(!activeEdges.contains(edge)){
                    activeEdges.add(edge);
                }
             }
            else{
                if(activeEdges.contains(edge))
                    activeEdges.remove(edge);
            }
        }
        
        return activeEdges;
    }
    
    private ArrayList<Integer> findIntersections(ArrayList<Integer> intersections,ArrayList<Edge> activeEdges,int currentY){
        intersections.clear();
        
        for(Edge edge : activeEdges){
            int x = edge.x1 + ((currentY-edge.y1) *(edge.dx))/(edge.dy);
            intersections.add(x);
        }
        
        return intersections;
    }
    
    
    private void scanLine(){
        
         ArrayList<Edge> activeEdges=new ArrayList();
         ArrayList<Integer> intersections=new ArrayList();
         
         Graphics g=getGraphics();
         g.setColor(Color.red);
         
         int yMin=getYmin();
         int yMax=getYmax();
         
         for(int y=yMin; y<yMax ;y++){
             
             activeEdges = updateActiveEdges(activeEdges,y);
             intersections=findIntersections(intersections,activeEdges,y);
            
             Collections.sort(intersections);
             
             for (int i = 0; i < intersections.size(); i += 2) {
                
                int x1 = intersections.get(i);
                
                if (i + 1 >= intersections.size()) 
                    break;

                int x2 = intersections.get(i+1);
                
                g.drawLine(x1, y, x2, y);
                
                try {
                    Thread.sleep(50);
                } catch (InterruptedException ex) {
                    Logger.getLogger(ScanLine.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
             
         }
         
    }
    
    public static void main(String []args){
        ScanLine s=new ScanLine();
        s.setSize(800, 800);
        s.setVisible(true);
        s.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        s.inputNoOfVertices();
        s.inputPolygon();
    }
}

class Edge {
    int x1, y1, x2, y2, dx, dy;

    Edge(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;

        this.dx = x2 - x1;
        this.dy = y2 - y1;
    }
}
