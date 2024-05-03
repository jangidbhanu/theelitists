import org.apache.poi.ss.usermodel.*;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class DeleteRowsInExcel {

    public static void main(String[] args) {
        String filePath = "path/to/your/excel/file.xlsx";
        deleteRows(filePath);
    }

    public static void deleteRows(String filePath) {
        try {
            FileInputStream fileInputStream = new FileInputStream(new File(filePath));
            Workbook workbook = WorkbookFactory.create(fileInputStream);
            Sheet sheet = workbook.getSheetAt(0); // Assuming you are working with the first sheet

            for (int i = sheet.getLastRowNum(); i >= 0; i--) {
                Row row = sheet.getRow(i);
                if (row != null) {
                    sheet.removeRow(row);
                }
            }

            fileInputStream.close();

            // Write the changes back to the Excel file
            FileOutputStream fileOutputStream = new FileOutputStream(filePath);
            workbook.write(fileOutputStream);
            fileOutputStream.close();

            workbook.close();
            System.out.println("All rows deleted successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
