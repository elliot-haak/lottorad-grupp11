package lottorad;

import java.io.File;
import java.util.logging.FileHandler;

public class Controller {
	private Model model = new Model(); 
	private View view = new View(); 
	private Filhantering fm = Filhantering.getInstance();
	
	//Konstruktorn 
	public Controller(Model model, View view, Filhantering fm) {
		this.model = model; 
		this.view = view; 
		//+ den med filhantering
		this.fm = fm;


	}
}
