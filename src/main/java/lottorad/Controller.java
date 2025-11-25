package lottorad;

import java.io.File;
import java.util.logging.FileHandler;

public class Controller {
	private Model model;
	private View view;
	private Filhantering fm;
	
	//Konstruktorn 
	public Controller(Model model, View view, Filhantering fm) {
		this.model = new Model();
		this.view = new View();
		//+ den med filhantering
		this.fm = Filhantering.getInstance();
	}
}
