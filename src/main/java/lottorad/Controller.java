package lottorad;


//import java.awt.event.ActionListener;
//import java.io.File;


public class Controller {

	private  Model model; 
	private  View view; 
	private Filhantering fm;
		
	//Konstruktorn 
	public Controller(Model model, View view, Filhantering fm) {
		this.model = model; 
		this.view = view; 
		//+ den med filhantering
		this.fm = fm;
	}
	
	
	//Hantera alla lyssnare i en metod
	public void listeners() {
		
		//Vid tryck på "rensa" skapas en ny array med 0 platser
		view.rensaLyssnare(e-> view.visaLottorad(new int[0])); 
		
		//Vid tryck på "slumpa" 
		view.slumpLyssnare(e -> {
			model.slump(); //metoden slump anropas och slumpar fram en lottorad på 7 unika siffror
			view.visaLottorad(model.getLottorad()); //visar lottoraden 
		});
		
		view.sparaLyssnare(e->{
			//try catch - felhantering
			//sparar ner lottoraden till filen
			
			try {
                System.out.println(view);
                String areaText = view.getAreaText();
                System.out.println(areaText + " areatext");
                if(areaText.isEmpty()) {
                    view.error("Saknas lottorad");
                    System.out.println("Saknas lottorad");
                    return;
                }
				boolean ok = fm.saveToCSV(model.getLottorad(), "lottorad.csv");
				if(!ok) {
					view.error("Could not save the file"); 
				}
				
			}catch(Exception err) {
				//Ropar på error-metoden i view för att visa felet för användaren
				view.error(err.getMessage()); 
			}		
		}); 
		
		
		view.lasaLyssnare(e->{ 
			//laddar filen och läser den
			try {
			int [] rad = fm.loadFromCSV("lottorad.csv");
			if(rad!=null) {
				view.visaLottorad(rad); 
			} else {
				view.error("No data found"); 
			}
			}catch(Exception err) {
				//Ropar på error-metoden i view för att visa felet för användaren
				view.error(err.getMessage()); 
				
			}
		});	
		
	}
	


}
