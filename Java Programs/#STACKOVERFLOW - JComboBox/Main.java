import java.awt.*;
 import java.awt.event.*;
 import javax.swing.*;

 public class Main extends JFrame implements ActionListener {
 String[] MuniArray = {"Allepo", "Avalon",};
 JComboBox MuniList = new JComboBox (MuniArray);
 JLabel lblText = new JLabel();

 public static void main(String[] args) {
    Main fr = new Main();
    centerFrame(fr);
    fr.setVisible(true);


 }
 private static void centerFrame(Main fr) {


 }
 public Main() {
    setLayout (new FlowLayout());
    setSize (400, 300);
    setTitle ("Solicitor Search");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    MuniList.setSelectedIndex(0);
    MuniList.addActionListener(this);
    add(MuniList);
    add(lblText);

}
public void actionPerformed(ActionEvent e) {
    if (e.getSource() == MuniList) {
        JComboBox cb = (JComboBox)e.getSource();
        String msg = (String)cb.getSelectedItem();
        switch (msg) {
            case "Allepo": lblText.setText("The attorney is Joe!");
            break;
            case "Avalon": lblText.setText("The attorney is Dana!");
            break;
	}
}
}
}