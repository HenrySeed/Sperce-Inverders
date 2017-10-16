#include <Adafruit_NeoPixel.h>
#include <avr/wdt.h>

#define PIN           2
#define NUMPIXELS     150
#define WIDTH         25
#define HEIGHT        6
#define BRIGHTNESS    0.4

#define SHOOT_SPEED   20
#define MOVE_SPEED    30
#define ALIENS        7

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint8_t menu[HEIGHT][WIDTH][3] = {
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}},
{{255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}},
{{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}},
{{255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}, {255, 221, 3}},
{{255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}, {255, 221, 3}, {255, 171, 3}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}, {255, 221, 3}, {255, 171, 3}, {255, 171, 3}}};

uint8_t win[HEIGHT][WIDTH][3] = {
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}},
{{255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}},
{{255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}},
{{255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}, {255, 221, 3}},
{{0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}, {255, 221, 3}, {255, 171, 3}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {78, 3, 255}, {78, 3, 255}, {3, 32, 255}, {3, 32, 255}, {3, 108, 255}, {3, 108, 255}, {57, 255, 3}, {57, 255, 3}, {255, 221, 3}, {255, 221, 3}, {255, 171, 3}, {255, 171, 3}}};

uint8_t forward = 1;
uint8_t alien_height = 0;
int player[] = {5, 13};
int aliens[ALIENS*4][2];

uint8_t colours[7][3] = {{255, 0, 0}, {255, 168, 0}, {251, 255, 0}, {26, 255, 0}, {0, 187, 255}, {0, 17, 255}, {140, 0, 255}};
uint8_t index = 0;
uint8_t state = 0; 

uint8_t hits = 0;

int shots[20][2];
int shot_index = 0;
int shot_wait = SHOOT_SPEED;

int move_wait = MOVE_SPEED;

void add_alien(int row, int col) {
  aliens[index][0] = row;
  aliens[index][1] = col;
  aliens[index+1][0] = row;
  aliens[index+1][1] = col + 1;
  aliens[index+2][0] = row + 1;
  aliens[index+2][1] = col;
  aliens[index+3][0] = row + 1;
  aliens[index+3][1] = col + 1;
  index += 4;
}

void set_pixel(int x, int y, int r, int g, int b, float brightness) {
  int n;
  if(y % 2 != 0){                           // odd
    n = (y * WIDTH) + (WIDTH - x - 1);
  } else {                                  // even
    n = (y * WIDTH) + x;
  }  
  strip.setPixelColor(n, r*brightness, g*brightness, b*brightness);
}

void draw_menu() {
  
  uint16_t row, col;
  for(row = 0; row < HEIGHT; row++) {
    for(col = 0; col < WIDTH; col++){
       set_pixel(col, row, menu[row][col][0], menu[row][col][1], menu[row][col][2], 0.2);
    }
  }
}

void draw_fin() {
  
  uint16_t row, col;
  for(row = 0; row < HEIGHT; row++) {
    for(col = 0; col < WIDTH; col++){
       set_pixel(col, row, win[row][col][0], win[row][col][1], win[row][col][2], 0.1);
    }
  }
}

void draw_field() {
  uint16_t row, col;
  for(row = 0; row < HEIGHT; row++) {
    for(col = 0; col < WIDTH; col++){
       set_pixel(col, row, 0, 0, 0, 0.2);
    }
  }
}

void draw_fail() {
  uint8_t fail_pixels[][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {2, 0}, {3, 0}, {2, 1}, 
                              {0, 5}, {1, 4}, {2, 4}, {3, 4}, {1, 6}, {2, 6}, {3, 6}, 
                              {2, 5}, {0, 8}, {1, 8}, {2, 8}, {3, 8}, {0, 10}, 
                              {1, 10}, {2, 10}, {3, 10}, {3, 11}};
  
  for(int i = 0; i < 24; i++){
    set_pixel(fail_pixels[i][1], fail_pixels[i][0]+1, 255, 0, 0, 1);
  }

  for(int row = 0; row < 6; row++){
    for(int col = 13; col < 24; col++){
      set_pixel(col, row, menu[row][col][0], menu[row][col][1], menu[row][col][2], 1);
    }
  }
}

void draw_aliens() {
  float n;
  int i;
  
  for(int j = 0; j < ALIENS*4; j++){
    n = j/4;
    i = (int) n;
    set_pixel(aliens[j][1], aliens[j][0], colours[i][0], colours[i][1], colours[i][2], BRIGHTNESS);
  }
}

void check_height() {
  int maximum = 0;
  
  for(int i = 0; i < ALIENS*4; i++){
      if(maximum < aliens[i][0]){
        maximum = aliens[i][0];
     }
  } 

   alien_height = maximum;
}

void move_aliens() {
  if(move_wait == 0){

    if(aliens[0][1] < 1){forward = 1;}
    
    if(aliens[(ALIENS*4)-1][1] > 23){
      forward = 0;
      for(int i = 0; i < ALIENS*4; i++){
        if(aliens[i][0] > -1 && aliens[i][1] > -1){
          aliens[i][0] += 1;
          
         }
      }  
      check_height();
    }
    
    for(int i = 0; i < ALIENS*4; i++){
      if(forward == 1){aliens[i][1] += 1;}
      if(forward == 0){aliens[i][1] -= 1;}
    }
    
    move_wait = MOVE_SPEED;
  }
}

void draw_player() {
  set_pixel(player[1], player[0], 255, 0, 0, 1);  
}

void check_hits() {
  for(int j = 0; j < 20; j++){
    for(int i = 0; i < ALIENS*4; i++){
      if(aliens[i][0] > -1 && aliens[i][0] < 6 && aliens[i][1] > -1 && aliens[i][1] < 24){ //checks if aliens on screen
        if(aliens[i][0] == shots[j][0] && aliens[i][1] == shots[j][1]){
          aliens[i][0] = -100;
          shots[j][0] = -100;
          hits += 1;
          break;
        }
      }
    }
  }
}

void draw_update_shots() {
  int start = 0;  // start of each block
  for(int i = 0; i < 20; i++){
    set_pixel(shots[i][1], shots[i][0], 255, 255, 255, 1);
    
    if(shots[i][0] > -1){
      shots[i][0] -= 1;
    }
  }
}

void fire() {
  if(shot_wait == 0){
    shots[shot_index][0] = player[0];
    shots[shot_index][1] = player[1];
  
    shot_index += 1;
    if(shot_index == 19){
      shot_index = 0;
    }
    shot_wait = SHOOT_SPEED;
  } 
}

void keys() {
  char val = Serial.read();

  if(val == 'a' && player[1] != 0){
    player[1] -= 1;
  } else if(val == 'd' && player[1] != 24){
    player[1] += 1;
  }else if(val == ' '){
    fire();
  } else if(val == 'r'){
    state = 0;
  }

  if(val == 'q'){wdt_enable(WDTO_15MS);for(;;){}}
}

void setup() {
  MCUSR = 0;
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
  Serial.println("Left up: W, Left down: S Right up: p Right down: ;");

  add_alien(0, 0);
  add_alien(0, 3);
  add_alien(0, 6);
  add_alien(0, 9);
  add_alien(0, 12);
  add_alien(0, 15);
  add_alien(0, 18);
}

void loop() {  
  if(state == 0){
 
    draw_menu();
    char val = Serial.read();
    if(val == ' ' || val == 'a' || val == 'd'){state = 1;}
    if(val == 'q'){wdt_enable(WDTO_15MS);for(;;){}}

  } else if(state == 1){
    keys();
    draw_field();
    draw_player();
    draw_update_shots();
    draw_aliens();
  
    move_aliens();
    
    check_hits();
    if(shot_wait > 0){shot_wait -= 1;}
    if(move_wait > 0){move_wait -= 1;}
    if(hits == (ALIENS*4)){state = 2;}
    if(alien_height > 4){state = 3;}
    
  } else if(state == 2){
    draw_fin();
    char val = Serial.read();
    if(val == ' ' || val == 'a' || val == 'd' || val == 'q'){wdt_enable(WDTO_15MS);for(;;){}}
    
  } else if(state == 3){
    draw_field();
    draw_fail();  
    char val = Serial.read();
    if(val == ' ' || val == 'a' || val == 'd' || val == 'q'){wdt_enable(WDTO_15MS);for(;;){}}
  }
  strip.show();
  delay(20);
}
















