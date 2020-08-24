public class StandartDeviation {

    private static void standartDeviation(double [] num, String type) {

        double sum = 0;
        double sd = 0;

        for(int i=0; i<num.length; i++)
        {
            sum = sum + num[i];
        }

        double average = (sum / num.length);

        System.out.println("Sum: " + sum);
        System.out.println("Average: " + average);

        for (int i=0; i<num.length;i++){

            if (type.toLowerCase().equals("sample")){
                sd += Math.pow((num[i] - average),2) / (num.length - 1);
            } else if (type.toLowerCase().equals("population")) {
                sd += Math.pow((num[i] - average),2) / (num.length);
            }
        }

        double standardDeviation = Math.sqrt(sd);
        System.out.println("This is " + type); 
        System.out.println("The standart deviation is : " + standardDeviation);
    }

    public static void main(String[] args) {

        double [] arr = {4,6,8,1,4};

        standartDeviation(arr,"sample");
        standartDeviation(arr,"population");
    }
}


