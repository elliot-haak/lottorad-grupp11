package lottorad;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;


//Majoriteten av filhnaterings koden är tagen från Pierres föreläsning 6
//Sedan har vi anpassat kod så den passar till vårat program
public class Filhantering {
    private static Filhantering instance = null;
    //Konstruktorn Filhantering som skriver ut till console när den tillkallas
    private Filhantering() {
        System.out.println("Filemanager created");
    }
    //skapande av instansen och kan enbart skapas här
    public static Filhantering getInstance(){
        //kontrollerar om det redan finns en instans. om int så skapas en ny
        if(instance == null){
            instance = new Filhantering();
        }

        return instance;
    }
    //metod som sparar filen, den tar emot en array med siffror och filnamnet på filen
    public boolean saveToCSV(int[] numbers, String fileName){

        //skapar ett object av filen så vi kan använda setWritable och setReadOnly
        File file = new File(fileName);
        //tar bort skrivskyddet så vi vi kan uppdatera filen
        file.setWritable(true);

        //Undantagshantering där vi kontrollerar om det går att spara filen.
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))){
            //hämtar dagens datum och tid
            LocalDate date = LocalDate.now();
            LocalTime time = LocalTime.now();
            //skriver det till filen tillsammans med radbrytning och lottorad
            writer.write("Datum: "+date+" tid: "+time+"\n");
            writer.write("Lottorad: ");

            //loopar igenom arrayen med nummer och sedan skrivet ut nummer + ,
            for(int x = 0; x < numbers.length; x++){
                //skriver ut numre till filen
                writer.write(String.valueOf(numbers[x]));
                //skrivet ut ett , på platsen efter numret som skrivs
                if(x < numbers.length - 1){
                    writer.write(",");
                }
            }
            //kör 2 radbrytningar så lottorader sparas mer grupperat och lättare att läsa.
            writer.newLine();
            writer.newLine();
            System.out.println("File saved");

            //efter filen har sparats så sätter vi skrivskydd på filen
            file.setReadOnly();
            return true;

            //fångar eventuella fel och skrivet ut error i consolen
        }catch(IOException err){
            System.out.println("Error " + err.getMessage());
            return false;
        }

    }
    //metod some läser upp alla lottorader i fil. tar emot namnet på filens namn
    //en 2 dimensionell array
    public int[][] loadFromCSV(String fileName){
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))){
            
            String line;
            //skapar en lista som innehåller lottoraderna
            List<int[]> allLottoRows = new ArrayList<>();

            //loop som kontrollerar om raderna har ett värde
            while((line = reader.readLine()) != null){

                //kontroll om raden har ett värde som börjar med "Lottorad"
                if(line.startsWith("Lottorad:")){
                    //Tar bort raden "Lottorad ur raden med längden på antal tecken och sedan trimmar bort det
                    //splittar sedan , så det är enbart siffror som sparas i part
                    //skapar en ny array som innehåller bara siffrorna
                    String onlyNumbers = line.substring(("Lottorad:").length()).trim();
                    String[] parts = onlyNumbers.split(",");
                    int[] numbers = new int[parts.length];

                    //loopar sedan igenom arrayen och omvandlar strängarn till int och tar bort eventuella mellanslag med trim
                    for(int x = 0; x < parts.length; x++){
                        numbers[x] = Integer.parseInt(parts[x].trim());
                    }
                    //lägger till arrayen i listan av lottorader
                    allLottoRows.add(numbers);

                }
            }

            //kontrollerar om listan är tom
            //är den tom så skrivet vi ut meddelande i pop up fönster
            if(allLottoRows.isEmpty()){
                System.err.println("No lottorows found");
                return null;
            }
            // går allt igenom så skriver vi ut i console att filen är läst som indikerar att allt gick som det ska
            System.out.println("File is read");

            //vi returnerar listan och konverterar den till en vanlig java array i 2 dimensionell skala med storlek av listans storlek
            return allLottoRows.toArray(new int[allLottoRows.size()][]);

            //här fångas alla fel av de vanligaste exceptions och printar ut olika meddelanden beroende på vilket fel som uppstår
        }catch(FileNotFoundException err){
            System.err.println("File does not exist");
            return null;

        }catch (IOException err){
            System.err.println("Could not read file");
            return null;

        }catch(NumberFormatException err){
            System.err.println("Invalid number");
            return null;
        }

    }
}
