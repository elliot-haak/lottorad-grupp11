package lottorad;


public class Main {
	public static void main(String[] args) {
		
		//Instansiera komponeneterna
		Model model = new Model(); //model-objekt som slumpar fram en lottorad
		View view = new View(); //Hanterar GUI, visar fönstret direkt 
		Filhantering fm = Filhantering.getInstance(); 
		
		//Koppla ihop alla komponenter via controllern
		Controller cont = new Controller(model, view, fm); 
		
		//lyssnare för knappar "startas" 
		cont.listeners(); 
		//visar frame 
		view.showFrame();
	
	}
}