import java.awt.*;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.*;

public class BouncingBall extends JFrame {
    static final int WIDTHb = 600;
    static final int HEIGHTb = 600;
    static final int DELAY = 10;
    static final int SIZE = 50;
    int count = 50;

    ArrayList<Oval> ovals = new ArrayList<>();

    BouncingBall() {
        setTitle("BouncingBall");
        setSize(600, 600);
        setLocation(300, 300);
        
        MyPanel panel = new MyPanel();

        Timer timer = new Timer(DELAY, e -> {
            for (Oval oval : ovals) {
                oval.update();
            }
            panel.repaint();
        });
        timer.start();

        creatOval();
        
        add(panel);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class Oval {
        int x, y;
        int xspeed, yspeed;
        Color col;
        Oval() {
            Random rand = new Random();
            x = rand.nextInt(WIDTHb-SIZE);
            y = rand.nextInt(HEIGHTb-SIZE);
            xspeed = rand.nextInt(7)+2;
            yspeed = rand.nextInt(7)+2;
            col = getRandomColor(rand);
        }

        Color getRandomColor(Random rand) {
            int r = rand.nextInt(256);
            int g = rand.nextInt(256);
            int b = rand.nextInt(256);
            return new Color(r,g,b);
        }

        public void update() {
            x += xspeed;
            y += yspeed;
            if (x >= (HEIGHTb - SIZE) || x < 0) {
                xspeed = (-xspeed);
            }
            if (y >= (WIDTHb-SIZE)|| y < 0) {
                yspeed = (-yspeed);
            }
        }

        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
        public Color getColor() {
            return col;
        }
    }

    void creatOval() {
        for (int i=0; i < count; i++) {
            Oval oval = new Oval();
            ovals.add(oval);
        }
    }

    class MyPanel extends JPanel {
        MyPanel() {
            setPreferredSize(new Dimension(WIDTHb, HEIGHTb));
            //setBackground(new Color(255, 0, 0));
        }
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            for (Oval oval : ovals) {
                Color c = oval.getColor();
                g.setColor(c);
                int x = oval.getX();
                int y = oval.getY();
                g.fillOval(x, y, SIZE, SIZE);
            }
        }
    }


    public static void main(String[]args) {
        new BouncingBall();
    }
}