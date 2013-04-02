#define UNIT           200       // Basic unit of time in ms
#define DOT            UNIT      // Duration of DOT "."
#define DASH           UNIT * 3  // Duration of DASH "-"
#define SIGNAL_GAP     UNIT      // Silence between DOT/DASH
#define LETTER_GAP     UNIT * 3  // Gap between two letters 
#define WORD_GAP       UNIT * 7  // Gap between two words 

int  led = 13;   
char inputstr;
int  index=0;
char inputbuffer[50]={'\0'};
char DOT_SYMBOL='.';
char DASH_SYMBOL='-';

char * arr_morse[] = {
    "-----",  // 0
    ".----",  // 1
    "..---",  // 2
    "...--",  // 3
    "....-",  // 4
    ".....",  // 5
    "-....",  // 6 
    "--...",  // 7
    "---..",  // 8
    "----.",  // 9
    ".-",     // A
    "-...",   // B
    "-.-.",   // C
    "-..",    // D
    ".",      // E
    "..-.",   // F
    "--.",    // G
    "....",   // H
    "..",     // I
    ".---",   // J
    "-.-",    // K
    ".-..",   // L
    "--",     // M
    "-.",     // N
    "---",    // O
    ".--.",   // P
    "--.-",   // Q
    ".-.",    // R
    "...",    // S
    "-",      // T
    "..-",    // U
    "...-",   // V
    ".--",    // W
    "-..-",   // X
    "-.--",   // Y
    "--.."    // Z
};
 
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void led_on(int duration){
  digitalWrite(led, HIGH);
  delay(duration);
}

void led_off(int duration){
  digitalWrite(led, LOW);
  delay(duration);
}

void convert_morse(char * buf){
  int i = 0;
  Serial.print("Morse code is:");
  while(buf[i]!='\0')
  { 
      if(buf[i]==DOT_SYMBOL)
      {
        Serial.print(buf[i]);
        led_on(DOT);
      }
      if(buf[i]==DASH_SYMBOL)
      {
        Serial.print(buf[i]);
        led_on(DASH);
      }
      i=i+1;
      //gap between DASH and DOT
      led_off(SIGNAL_GAP); 
  }
  Serial.println();
}
 
void convert_string(char * inbuffer){
  int i = 0;
  char letter;  
  letter = inbuffer[i];
  while(letter!='\0')
  {
      letter=toupper(letter);
      
      //convert 0-9 numbers into morsecode
      if((letter>='0')&&(letter<='9'))
      {
        Serial.print("character is:");
        Serial.print(letter);
        Serial.println();
        //48 is ascii value of 0, subtract this to get array index
        convert_morse(arr_morse[letter-48]);    
        led_off(LETTER_GAP); 
      } 
      //convert A-Z alphabets into morsecode (ignore case)     
      else if((letter>='A')&&(letter<='Z')){
        Serial.print("character is:");
        Serial.print(letter);
        Serial.println();
        //65 is ascii value of A, subtract to get array index of alphabets,+10 for offset
        convert_morse(arr_morse[letter-65+10]);  
        led_off(LETTER_GAP); 
      }
      //handle space between words      
      else if(letter==' '){
        Serial.print("space between words");
        Serial.println();
        led_off(WORD_GAP); 
      }
      //handle unnecessary characters
      else{
          Serial.print("ignored character");
          Serial.println();
        }
      i=i+1;
      letter = inbuffer[i];
  }
}

void loop(){
  if(Serial.available())
 {
          inputstr = (char)Serial.read();              
          if(inputstr=='\n')
          {
            //process string
            convert_string(inputbuffer);
            //clear buffer on enter and set index to 0
            memset(&inputbuffer[0], 0, sizeof(inputbuffer));
            index=0;
            Serial.println("String finished!");
          }
          else
          { 
            //else keep adding to buffer         
            inputbuffer[index]=inputstr;
            index=index+1;
          }
  }
}
