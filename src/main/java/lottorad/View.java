package lottorad;
import java.awt.*;
import java.awt.event.ActionListener;
//import java.io.IOException;   try and catch 
import javax.swing.*;

public class View extends JFrame {
	
	private JFrame frame = new JFrame("Lotto"); 
	private JTextArea area = new JTextArea();
	//knappar 
	private JButton slumpKnapp = new JButton("Slumpa lottorad"); 
	private JButton rensaKnapp = new JButton("Rensa"); 
	//panel 
	private JPanel panel = new JPanel(); 
	
	//meny
	private JMenuBar menu = new JMenuBar();
	private JMenu menuTitel = new JMenu("File");
	
	//private JMenuItem menuItem = new JMenuItem();
	//private JMenuItem slumpVal;
	private JMenuItem sparaVal;
	private JMenuItem lasaVal; 
	
	//måste lägga det i konstruktorn 
	public View() {
		
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE); 
		frame.setSize(250,200);
		frame.setResizable(false); 
		frame.setLayout(new FlowLayout());
	    
	
		//Lägg till i meny 
		//slumpVal = new JMenuItem("Slumpa lotter");
		sparaVal = new JMenuItem("Spara lotter");
		lasaVal = new JMenuItem("Läsa lotter");
		menu.add(menuTitel); 
		//menuTitel.add(slumpVal);
		menuTitel.add(sparaVal);
		menuTitel.add(lasaVal); 
		
	
		//Lägger in i frame 
		frame.add(area);  
		area.setEditable(false); // så man inte kan skriva i den 
		
		frame.setJMenuBar(menu); // så den inte hamnar mitt i. 
		panel.add(slumpKnapp); 
		panel.add(rensaKnapp); 
		frame.add(panel); 
		
		//Göra allt synligt 
		frame.setVisible(true);
	
	}
	
	//lyssnare Menyvalen 
	public void rensaLyssnare(ActionListener lyssnare) {

		rensaKnapp.addActionListener(lyssnare); 
		
	}
	public void slumpLyssnare(ActionListener lyssnare) {

		slumpKnapp.addActionListener(lyssnare); 
		
	}
	public void sparaLyssnare(ActionListener lyssnare) {
		
		sparaVal.addActionListener(lyssnare); 
		
	}
	public void lasaLyssnare(ActionListener lyssnare) {
		
		lasaVal.addActionListener(lyssnare); 
		
	}
	
	//textArea kan bara visa text så vi behöver lägga till dem som String inte Int 
	public void visaLottorad(int[] rad) {
	    String text = "";
	    for (int lott : rad) {
	        text += lott + " ";
	    }
	    area.setText(text);
	}
	// Från chatten men bättre med try and catch tänker jag med vanliga error msg 
	public void error(String msg) {
	    JOptionPane.showMessageDialog(frame, msg);
	}



}
