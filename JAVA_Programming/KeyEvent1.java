import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class KeyEvent1 extends JFrame {
    public KeyEvent1() {
        setLocation(600, 300);
        setTitle("Key Events Example");
        setSize(300, 200);

        JPanel panel = new JPanel();
        panel.setBackground(Color.LIGHT_GRAY);
        panel.setLayout(new BorderLayout());

        JLabel label = new JLabel("Press any key...");
        label.setFont(new Font("Arial", Font.BOLD, 24));
        label.setHorizontalAlignment(JLabel.CENTER); // 텍스트 가운데 정렬
        panel.add(label, "North");

        JLabel label2 = new JLabel("");
        label2.setFont(new Font("Arial", Font.BOLD, 24));
        label2.setHorizontalAlignment(JLabel.CENTER);// 텍스트 가운데 정렬
        panel.add(label2, "Center");

        panel.addKeyListener(new KeyListener() {
            public void keyPressed(KeyEvent e) {
                int keyCode = e.getKeyCode();
                String keyText = KeyEvent.getKeyText(keyCode);
                label2.setText(""+ keyText);
            }
            public void keyTyped(KeyEvent e) { }

            public void keyReleased(KeyEvent e) { }
        });

        add(panel);
        panel.setFocusable(true);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    }

    public static void main(String[] args) {
        new KeyEvent1();
    }
}