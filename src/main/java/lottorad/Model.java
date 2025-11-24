package lottorad;
import java.util.Random;

public class Model {
    // En lottorad består av 7 unika siffror från 1 till och med 35.
    private int[] lottorad = new int[7]; 
    private Random random = new Random(); 
    
    public void slump() {
        
        for (int i = 0; i < lottorad.length; i++) {
            //lokala variabler kan inte vara private 
            int lott = random.nextInt(35) + 1;
            boolean inteUnik = true;

            // så länge alla tal inte är unika så slumpas det om tills alla är unika. 
            while (inteUnik) {
                inteUnik = false; 

                // kolla mot redan ifyllda tal
                for (int j = 0; j < i; j++) {
                    if (lottorad[j] == lott) {
                        inteUnik = true;         
                        lott = random.nextInt(35) + 1; 
                        break;            
                    }
                }
            }

            // Spara alla unika tal i vektorn 
            lottorad[i] = lott;
        }
    }
    public int[] getLottorad(){
    	return lottorad; 
    }
}

