package lottorad;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
public class Filhantering {
    private static Filhantering instance = null;

    private Filhantering() {
        System.out.println("Filemanager created");
    }

    public static Filhantering getInstance(){
        if(instance == null){
            instance = new Filhantering();
        }

        return instance;
    }

    public boolean saveToCSV(int[] numbers, String fileName){

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))){
            LocalDate date = LocalDate.now();
            LocalTime time = LocalTime.now();
            writer.write("Datum: "+date+" tid: "+time+"\n");
            writer.write("Lottorad: ");
        
            for(int x = 0; x < numbers.length; x++){
                writer.write(String.valueOf(numbers[x]));
                if(x < numbers.length - 1){
                    writer.write(",");
                }
            }

            writer.newLine();
            writer.newLine();
            System.out.println("File saved");
            return true;

        }catch(IOException err){
            System.out.println("Error " + err.getMessage());
            return false;
        }

    }

    public int[] loadFromCSV(String fileName){
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))){


            String line;
            while( (line = reader.readLine() ) != null) {
                //System.out.printf(line + " \n");
                if(!line.isEmpty()) {
                    if(!line.contains("Datum")) {
                        System.out.println(line + " !!");
                    }
                }

            }

            if(line == null || line.trim().isEmpty()){
                System.err.println("File is empty");
                return null;
            }

            String[] parts = line.split(",");
            int[] numbers = new int[parts.length];

            for(int x = 0; x < parts.length; x++){
                numbers[x] = Integer.parseInt(parts[x].trim());
            }

            System.out.println("File is read");

            return numbers;

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
