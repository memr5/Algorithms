//line clipping with mouse interface
package clipping;

import java.util.ArrayList;
import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Clipping extends JFrame{

    int prevX,prevY;
    int count=0;
    int state=0;
    int noOfLines;
    int xw,yw,width,height;
    private int xMin,xMax,yMin,yMax;
    private ArrayList<Line> lines=new ArrayList();
  
    private static final int INSIDE=0;
    private static final int TOP=8;
    private static final int BOTTOM=4;
    private static final int RIGHT=2;
    private static final int LEFT=1;
    
    @Override
    public void paint(Graphics g){
        Input(g);
    }
    
    public void drawWindow(Graphics g){
        g.setColor(Color.red);
        g.drawRect(xw,yw,width,height);
        xMin=xw;
        xMax=xw+width;
        yMin=yw+height;
        yMax=yw;
        g.setColor(Color.BLACK);
    }
    
    public void Input(Graphics g){
        
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the coordinates of top left corner of window");
        System.out.println("Enter x:");
        xw=sc.nextInt();
        System.out.println("Enter y:");
        yw=sc.nextInt();
        System.out.println("Enter the width: ");
        width=sc.nextInt();
        System.out.println("Enter the height:");
        height=sc.nextInt();
        drawWindow(g);
        System.out.println("Enter the no of lines you want to clip");
        noOfLines=sc.nextInt();
        System.out.println("Draw the lines ");
        addMouseListener(mouselistener);
        
    }
    
    
    private MouseListener mouselistener=new MouseListener() {
        @Override
        public void mouseClicked(MouseEvent e) {
            int x=e.getXOnScreen();
            int y=e.getYOnScreen();
            Graphics g=getGraphics();
                        
            if(state==0){
                prevX=x;
                prevY=y;
                state=1;
            }
            else{
                lines.add(new Line(prevX,prevY,x,y));
                g.drawLine(prevX, prevY, x, y);
                 count++;
                state=0;
            }
           
            if(count==noOfLines){
                removeMouseListener(mouselistener);
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException ex) {
                    Logger.getLogger(Clipping.class.getName()).log(Level.SEVERE, null, ex);
                }
                g.clearRect(0, 0, 800, 800);
                output(g);
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
    
    private int computeOutcode(int x,int y){
        int outcode=INSIDE;
        
        
        if(x < xMin)
            outcode=outcode | LEFT;
        else if(x > xMax)
            outcode=outcode | RIGHT;
        if(y < yMax)
            outcode=outcode | TOP;
        else if(y > yMin)
            outcode=outcode | BOTTOM;
        return outcode;
        
    }
    
    public void drawClippedLine(Graphics g,int x1,int y1,int x2,int y2){
        
        int outcode1=computeOutcode(x1,y1);
        int outcode2=computeOutcode(x2,y2);
        
        while(true){
            
            if((outcode1|outcode2)==0){
                g.drawLine(x1, y1, x2, y2);
                break;
            }
            else if((outcode1&outcode2)!=0)
                break;
            else{
                int x,y;
                int outcode;
                if(outcode1!=0)
                    outcode=outcode1;
                else
                    outcode=outcode2;
                
                if((outcode&TOP)!=0){
                    x=x1+(yMax-y1)*(x2-x1)/(y2-y1);
                    y=yMax;
                }
                else if((outcode&BOTTOM)!=0){
                    x=x1+(yMin-y1)*(x2-x1)/(y2-y1);
                    y=yMin;
                }
                else if((outcode&RIGHT)!=0){
                    y=y1+(xMax-x1)*(y2-y1)/(x2-x1);
                    x=xMax;
                }
                else{
                    y=y1+(xMin-x1)*(y2-y1)/(x2-x1);
                    x=xMin;
                }
                if (outcode == outcode1) {
                    x1 = x;
                    y1 = y;
                    outcode1 = computeOutcode(x1, y1);
                } else {
                    x2 = x;
                    y2 = y;
                    outcode2 = computeOutcode(x2, y2);
                }
            }
            
        }
        
    }
    
    
    public void output(Graphics g){
        drawWindow(g);
      //  System.out.print(lines.size());
        for(Line line:lines){
         //   System.out.println(line.x1+"  "+line.y1+"  "+line.x2+"  "+line.y2);
            drawClippedLine(g,line.x1,line.y1,line.x2,line.y2);
        }
    }
    public static void main(String[] args) {
       Clipping c=new Clipping();
       c.setSize(800,800);
       c.setVisible(true);
       c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
}


class Line{

int x1,y1,x2,y2;

  Line(int x1,int y1, int x2, int y2){
      this.x1=x1;
      this.y1=y1;
      this.x2=x2;
      this.y2=y2;
  }

}