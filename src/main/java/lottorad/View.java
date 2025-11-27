package lottorad;
import java.awt.*;
import java.awt.event.ActionListener;
import javax.swing.*;


public class View extends JFrame {
	//area
	private JTextArea area = new JTextArea();

	//knappar 
	private JButton slumpKnapp = new JButton("Slumpa lottorad"); 
	private JButton rensaKnapp = new JButton("Rensa"); 
	
	//panel och scroller 
	private JPanel panel = new JPanel(); 
	private JScrollPane scroller = new JScrollPane(area); 
	
	//meny
	private JMenuBar menu = new JMenuBar();
	private JMenu menuTitel = new JMenu("File");
	private JMenuItem sparaVal;
	private JMenuItem lasaVal; 
	
	//måste lägga in de privata attributen i konstruktorn för att använda dem 
	public View() {
		System.out.println("View skapad!");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setSize(300,200);
		this.setResizable(false); 
		this.setLayout(new BorderLayout(10,10));
		this.setLocationRelativeTo(null); 
		this.setTitle("Slumpa lotter");
	    
		//Lägg till items och titel i meny 
		sparaVal = new JMenuItem("Spara lotter");
		lasaVal = new JMenuItem("Läsa lotter");
		menu.add(menuTitel); 
		menuTitel.add(sparaVal);
		menuTitel.add(lasaVal); 
		
		//area och panel hantering 
		area.setEditable(false); // så man inte kan skriva i den 
		panel.setLayout(new FlowLayout(FlowLayout.CENTER,30,10)); 
		
		//Lägger in allt i frame och panel och meny 
		this.setJMenuBar(menu); // så menyn inte hamnar mitt i. 
		panel.add(slumpKnapp); 
		panel.add(rensaKnapp); 
		this.add(panel, BorderLayout.SOUTH); 
		this.add(scroller, BorderLayout.CENTER);
		
	}
	public void visaSparadLottDialog() {
	    JOptionPane.showMessageDialog(
	        this,                          // fönstret som dialogen hör till
	        "Du har sparat lotten.",       // meddelandetext
	        "Lott sparad",                 // titel på popupen
	        JOptionPane.INFORMATION_MESSAGE // ikon-typ (info)
	    );
	}

	//Metod för att visa frame 
	public void showFrame() {
		setVisible(true);
	}
	
	//lyssnare Meny och knappvalen 
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
	
	//getmetod för att hämta texten i area
    public String getAreaText() {
        return area.getText();
    }
    public void setText(String text){
        area.setText(text);
    }



}
