package lottorad;

public class Controller {
	private Model model;
	private View view;
	private Filhantering fm;
	
	//Konstruktorn 
	public Controller(Model model, View view) {
        new Model();
        new View();
        view.showFrame();

        //+ den med filhantering
		this.fm = Filhantering.getInstance();
	}
}
