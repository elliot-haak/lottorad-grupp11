package lottorad;
import java.awt.*;
import java.awt.event.ActionListener;
//import java.io.IOException;   try and catch 
import javax.swing.*;
import java.time.LocalDate;
import java.time.LocalTime;

public class View extends JFrame {
	private JFrame frame = new JFrame(); 
	private JTextArea area = new JTextArea();

	//knappar 
	private JButton slumpKnapp = new JButton("Slumpa lottorad"); 
	private JButton rensaKnapp = new JButton("Rensa"); 
	
	//panel 
	private JPanel panel = new JPanel(); 
	
	//meny
	private JMenuBar menu = new JMenuBar();
	private JMenu menuTitel = new JMenu("File");
	private JMenuItem sparaVal;
	private JMenuItem lasaVal; 
	
	//Använder till id till lottrader 
	private LocalDate date = LocalDate.now();
	private LocalTime time = LocalTime.now();
	
	//måste lägga det i konstruktorn 
	public View() {
		System.out.println("View skapad!");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setSize(300,200);
		this.setResizable(false); 
		this.setLayout(new BorderLayout(10,10));
		this.setLocationRelativeTo(null); 
		this.setTitle("Slumpa lotter");
	    
		//Lägg till i meny 
		sparaVal = new JMenuItem("Spara lotter");
		lasaVal = new JMenuItem("Läsa lotter");
		menu.add(menuTitel); 
		menuTitel.add(sparaVal);
		menuTitel.add(lasaVal); 
		
		//area och panel 
		area.setEditable(false); // så man inte kan skriva i den 
		panel.setLayout(new FlowLayout(FlowLayout.CENTER,30,10)); 
		
		//Lägger in i frame och panel och meny 
		this.setJMenuBar(menu); // så menyn inte hamnar mitt i. 
		this.add(area); 
		panel.add(slumpKnapp); 
		panel.add(rensaKnapp); 
		this.add(panel, BorderLayout.SOUTH); 
		
		//Använder till id till lottrader i filhantering 
		System.out.println("Datum: "+date +" Tid: "+ time);
	  
		
	}
	public void showFrame() {
		setVisible(true);
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
    // Visa error message
	public void error(String msg) {
	    JOptionPane.showMessageDialog(this, msg);
	}
    public String getAreaText() {
        return area.getText();
    }
    public void setText(String text){
        area.setText(text);
    }


}
