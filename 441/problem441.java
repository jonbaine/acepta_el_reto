
import java.math.BigDecimal;
import java.util.Scanner;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;

public class problem441 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    BigDecimal one = new BigDecimal(1);
    String number;
    //Set format stuff.
    DecimalFormatSymbols formatSymbols = new DecimalFormatSymbols();
    formatSymbols.setDecimalSeparator(',');
    formatSymbols.setGroupingSeparator('.');
    DecimalFormat df = new DecimalFormat("#,##0.###", formatSymbols);
    df.setGroupingSize(3);

    while (sc.hasNext()) {
      number = sc.next();
      BigDecimal plus = new BigDecimal(number.replace(".", "")).add(one);
      System.out.println(df.format(plus));
    }
  }
}
