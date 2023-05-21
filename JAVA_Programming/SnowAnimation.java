import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.Timer;

public class SnowAnimation extends JFrame {

    private static final int WIDTH = 800;
    private static final int HEIGHT = 600;
    private static final int MAX_SNOW = 100;
    private static final int DELAY = 20;

    private MyPanel panel;
    private JButton addButton;
    private JButton removeButton;
    private int snowCount = 10;
    private ArrayList<Snowflake> snowflakes = new ArrayList<>();
    private Image snowImage;

    public SnowAnimation() {
        setTitle("Snow Animation");
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel buttonPanel = new JPanel();
        ImageIcon snowIcon = new ImageIcon("snow.png");
        snowImage = snowIcon.getImage();
        
        panel = new MyPanel();
        add(panel);

        addButton = new JButton("Add Snow");
        panel.add(addButton);
        addButton.addActionListener(e -> {
        	if (snowCount < MAX_SNOW) {
                snowCount++;
                createSnowflakes();
            }
        });
        
        removeButton = new JButton("Remove Snow");
        panel.add(removeButton);
        removeButton.addActionListener(e -> {
        	if (snowCount > 1) {
                snowCount--;
                createSnowflakes();
            }
        });
        
        Timer timer = new Timer(DELAY, e -> {
            for (Snowflake snowflake : snowflakes) {
                snowflake.update();
            }
            panel.repaint();
        });
        timer.start();
        
        createSnowflakes();
        
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void createSnowflakes() {
        snowflakes.clear();
        for (int i = 0; i < snowCount; i++) {
            Snowflake snowflake = new Snowflake();
            snowflakes.add(snowflake);
        }
        panel.repaint();
    }

    private class MyPanel extends JPanel {
        public MyPanel() {
            setPreferredSize(new Dimension(WIDTH, HEIGHT));
            setBackground(new Color(100, 200, 250));
        }
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            for (Snowflake snowflake : snowflakes) {
                g.drawImage(snowImage, snowflake.getX(), snowflake.getY(), null);
            }
        }
    }

    private class Snowflake {
        private int x;
        private int y;
        private int yspeed;
        private int xspeed;
        
        public Snowflake() {
            Random rand = new Random();
            x = rand.nextInt(WIDTH);
            y = rand.nextInt(HEIGHT);
            xspeed = rand.nextInt(3) -1;
            yspeed = rand.nextInt(5) + 2;
        }

        public void update() {
            y += yspeed;
            x += xspeed;
            if (y > HEIGHT) {
                y = 0;
            }
        }
        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
    }

    public static void main(String[] args) {
        SnowAnimation animation = new SnowAnimation();
    }
}
