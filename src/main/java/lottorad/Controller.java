package lottorad;


public class Controller {

	private  Model model; 
	private  View view; 
	private Filhantering fm;
		
	//Konstruktorn 
	public Controller(Model model, View view, Filhantering fm) {
		this.model = model; 
		this.view = view; 
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
		
		//Lyssnare för spara-knappen 
		view.sparaLyssnare(e->{
			//sparar ner lottoraden till filen
			
			try {
                System.out.println(view);
                String areaText = view.getAreaText();
                System.out.println(areaText + " areatext");
               
                //Om textarean är tom 
                if(areaText.isEmpty()) {
                    view.error("Saknas lottorad");
                    view.setText("Kunde inte spara");
                    System.out.println("Saknas lottorad");
                    return;
                }
                // Om man sparar samma lotto två i rad
                if(areaText.contains("sparat")) {
                    view.error("Måste dra ny lottorad");
                    System.out.println("Måste dra ny lottorad");
                    return;
                }
                //Sparar ner lottoraden till csv-filen 
				boolean ok = fm.saveToCSV(model.getLottorad(), "lottorad.csv");
			
				//Om något går fel med sparandet visas error
				if(!ok) {
					view.error("Kunde inte spara filen"); 
				}
				
				//Visar för användaren att filen är sparad
                view.setText("sparat fil");
				
			}catch(Exception err) {
				//Ropar på error-metoden i view för att visa felet för användaren
				view.error(err.getMessage()); 
			}		
		}); 
		
		//lyssnare för läsa-knappen
		view.lasaLyssnare(e->{ 
			//laddar filen och läser den
			try {
				//läser in sparade lotter från csv filen i en tvådimensionell array
			    int [][] rad = fm.loadFromCSV("lottorad.csv");
              
			    //OM ingen data hittas skickas ett felmeddelande
			    if(rad == null){
                    System.err.println("Ingen data hittad");
                }
			    //Stringbuilder för att bygga upp en text (en lottorad) som ska visas för användaren
                StringBuilder text = new StringBuilder();

                //loopar igenom varje sparad rad
                for(int x = 0; x<rad.length; x++){
                	//För varje lottorad så läggs en rubrik 
                    text.append("Lottorad ").append(x + 1).append(": ");

                    //loopar igenom varje rummer i den aktuella raden och lägger till det i texten
                    for(int num : rad[x]){
                        text.append(num). append(" ");
                    }
                    //Radbrytning efter varje lottorad
                    text.append("\n");
                }
                //Visar den färdiga texten för användaren
                view.setText(text.toString());

			}catch(Exception err) {
				//Ropar på error-metoden i view för att visa felet för användaren
				view.error(err.getMessage()); 
				
			}
		});	
		
	}
	


}
