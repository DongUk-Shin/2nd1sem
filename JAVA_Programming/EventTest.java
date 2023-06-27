import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/*
public class MyFrame extends JFrame implements ActionListener
    public void actionPerformed(ActionEvent e) //프레임 클래스에서 구성
*/
public class EventTest extends JFrame{
    JButton b1, b2;
    JLabel label;
    int count = 0;
    
    /*
    class MyListener implements ActionListener //내부클래스
        public void actionPerformed(ActionEvent e) 
     */
    public EventTest() {
        setLocation(600, 300);
        setTitle("test");
        setSize(300, 300);
        setLayout(new GridLayout(2, 1));


        JPanel panel1 = new JPanel(new FlowLayout());
        panel1.setBackground(Color.LIGHT_GRAY);

        JPanel panel2 = new JPanel(new FlowLayout());
        panel2.setBackground(Color.DARK_GRAY);


        b2 = new JButton("Decrease");
        b2.setBackground(Color.ORANGE);
        panel1.add(b2);
        b2.addActionListener(new ActionListener() { //ActionListener 구현( 익명클래스 )
            public void actionPerformed(ActionEvent e) {
                count--;
                label.setText(""+ count);
            }
        });
    
        b1 = new JButton("Increase");
        b1.setBackground(Color.green);
        panel1.add(b1);
        b1.addActionListener(e -> { //람다식
            count++;
            label.setText(""+ count);
        });


        label = new JLabel("" + count);
        label.setFont(new Font("Arial", Font.BOLD, 50));
        label.setForeground(Color.black);
        panel2.add(label);

        add(panel1);
        add(panel2);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new EventTest();
    }
}