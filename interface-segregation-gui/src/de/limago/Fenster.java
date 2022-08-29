package de.limago;

import java.awt.*;
import java.awt.event.*;

public class Fenster extends Frame {


    public Fenster()  {

        setSize(300, 300);
        addWindowListener(new MyWindowListener());
        Button button = new Button("Drück mich");
        button.addActionListener(e->beenden());
        add(button);
    }

    private void beenden() {
        dispose();System.exit(0);
    }
    public static void main(String[] args) {
	    new Fenster().setVisible(true);
    }

    class MyWindowListener extends WindowAdapter {
        @Override
        public void windowClosing(WindowEvent e) {
           beenden();
        }
    }

}
