import javax.swing.JFrame;
import java.awt.BorderLayout;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;

public class TableGenerator{
    public static void main(String[] args){
        JFrame win = new JFrame("ECE POV Table Code Generator");

        JPanel newPanel = new ControlPanel(win);
        win.add(newPanel);
        win.setSize(720, 600);
        win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        win.setVisible(true);
        
    }
}

class ControlPanel extends JPanel implements ActionListener{
    JFrame mainWin;
    JLabel promptLabel = new JLabel("Enter the text:");
    JTextField inputText = new JTextField("", 20);
    JButton genButton = new JButton("Generate");
    JPanel topPanel = new JPanel();
    JTextArea resultArea = new JTextArea();
    JScrollPane resultPane = new JScrollPane(resultArea);
    JPanel testPanel = new JPanel();
    ControlPanel(JFrame win){
        mainWin = win;
        resultArea.setEditable(false);
        genButton.addActionListener(this);
        
        
        topPanel.add(promptLabel);
        topPanel.add(inputText);
        topPanel.add(genButton);
        this.setLayout(new BorderLayout());
        //this.add(resultPane, BorderLayout.CENTER);
        this.add(testPanel, BorderLayout.CENTER);
        this.add(topPanel, BorderLayout.NORTH);

    }
    
    public void actionPerformed(ActionEvent e){
        // BufferedImage image = new BufferedImage(inputText.getText().length()*24, 24, BufferedImage.TYPE_INT_ARGB);
        BufferedImage image = new BufferedImage(96, 96, BufferedImage.TYPE_INT_ARGB);

        Graphics2D g = (Graphics2D)image.getGraphics();
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, image.getWidth(), image.getHeight());
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", 0, 24));
        // Point p = SwingUtilities.convertPoint(mainWin, 0, 0, image);
        g.drawString(inputText.getText(), 0, 15);
        
        testPanel.getGraphics().drawImage(image, 0, 0, this);
    }

    
}