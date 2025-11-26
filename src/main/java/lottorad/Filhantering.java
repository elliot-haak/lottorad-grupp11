package lottorad;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;

public class Filhantering {

    private static Filhantering instance = null;

    private Filhantering() {
        System.out.println("Filemanager created");
    }

    public static Filhantering getInstance() {
        if (instance == null) {
            instance = new Filhantering();
        }
        return instance;
    }

    public boolean saveToCSV(int[] numbers, String fileName) {

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))) {
            LocalDate date = LocalDate.now(); 
            LocalTime time = LocalTime.now();
            writer.write("Lottorad: ");

            for (int x = 0; x < numbers.length; x++) {
                writer.write(String.valueOf(numbers[x]));
                if (x < numbers.length - 1) {
                    writer.write(",");
                }
            }
            writer.write("\n" + "Datum: " + date + " tid: " + time);
            writer.newLine();
            writer.newLine();
            System.out.println("File saved");
            return true;

        } catch (IOException err) {
            System.out.println("Error " + err.getMessage());
            return false;
        }
    }

    public int[] loadFromCSV(String fileName) {

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {

            String line = reader.readLine();
            //sparar sista lottraden 
            String numberLine = null;  

            // Läser hela filen
            while(line != null) {
            	line = line.trim(); 
            	
            	// om raden börjar med "Lottorad:" sparar vi lottoraden utan "Lottorad:" i numberLine
                if (!line.isEmpty() && line.startsWith("Lottorad:")) {
                    
                    numberLine = line.substring("Lottorad:".length()).trim();
                }
                //nu läser vi raden 
                line = reader.readLine(); 
            }
                //Om ingen lottrad hittas 
                if (numberLine == null || numberLine.trim().isEmpty()) {
                    System.err.println("File is empty");
                    return null;
                }
                //Gör det till siffror 
                String[] parts = numberLine.split(",");
                int[] numbers = new int[parts.length];

                for (int x = 0; x < parts.length; x++) {
                    numbers[x] = Integer.parseInt(parts[x].trim());
                }

                System.out.println("File is read");
                return numbers;
            	
            
            
        //Olika catch beroende på vad det blir för slags error 
        } catch (FileNotFoundException err) {
            System.err.println("File does not exist");
            return null;

        } catch (IOException err) {
            System.err.println("Could not read file");
            return null;

        } catch (NumberFormatException err) {
            System.err.println("Invalid number");
            return null;
        }
    }
}
