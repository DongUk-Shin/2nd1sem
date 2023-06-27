import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class MouseTest extends JFrame {
    int img_x = 50;
    int img_y = 50;
    int count = 1;

    public MouseTest() {
        setLocation(600, 300);
        setTitle("MouseEvent");
        setSize(1000, 500);
        JPanel panel = new JPanel();
        panel.setLayout(null);

        ImageIcon img = new ImageIcon("C:\\car.png");

        JLabel label = new JLabel("Score "+ count);
        label.setFont(new Font("Arial", Font.BOLD, 20));
        label.setLocation(10, 10);
        label.setSize(100, 30);
        panel.add(label);


        JButton button = new JButton("");
        button.setBackground(Color.YELLOW);
        button.setIcon(img);
        button.setLocation(img_x, img_y);
        button.setSize(120, 100);
        button.addActionListener(e-> {
            count++;
            label.setText("Score "+count);
        });

        panel.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                img_x = e.getX();
                img_y = e.getY();
                count++;
                label.setText("Score " + count);
                button.setLocation(img_x, img_y);
            }
        });

        
        panel.add(button);
        add(panel);
        panel.requestFocus();
        panel.setFocusable(true);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    }

    public static void main(String[] args) {
        new MouseTest();
    }
}