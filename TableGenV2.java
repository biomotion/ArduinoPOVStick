import javax.swing.JFrame;
import java.awt.BorderLayout;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;

public class TableGenV2{
    public static void main(String[] args){
        JFrame win = new JFrame("ECE POV Table Code Generator");
2
        JPanel newPanel = new ControlPanel(win);
        win.add(newPanel);
        win.setSize(720, 600);
        win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        win.setVisible(true);
        
    }
}