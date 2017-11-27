#define ROOF 2
#define FENCE_RIGHT 3
#define FENCE_LEFT 4
#define WINDOW 5
#define WALKWAY 6
#define PANEL1 7
#define PANEL2 8
#define PANEL3 9


#define TRIGGER_PIN 12

#define RANDOM_PIN A4
#define ON_PIN A3
#define OFF_PIN A2

#define AUDIO_PIN A0
#define RANDOM_MODE_PINOUT 53
#define RANDOM_MODE_SPEED 500
#define PIN_LED_BEAT 10

void runSequences(int sequences[]);
bool isOffBeat(int i);
boolean inArray(int array[], int element, int arraySize);

// Channel Setup
int channels[] = {ROOF,FENCE_RIGHT,FENCE_LEFT,WINDOW,WALKWAY,PANEL1,PANEL2,PANEL3};
#define CHANNEL_COUNT 8

// BPM Setup
unsigned int bpm = 592;
unsigned int MS_per_beat = 0;

// Counters
uint8_t buttonCounter = 0;
uint8_t section = 0;
uint8_t beatCounter = 0;
uint8_t loopCounter = 0;


// Defaults
uint8_t sectionLength;
bool ended = false;
bool musicStarted = false;

// Section Arrays
int intro1_sections[1] = {0};
int intro2_sections[1] = {1};
int chorus1_sections[4] = {2,5,12,19};
int chorus21_sections[4] = {3,6,13,20};
int post_chorus_sections[3] = {4,11,18};
int post_chorus2_sections[1] = {7};
int post_chorus3_sections[1] = {14};
int bridge1_sections[1] = {8};
int bridge2_sections[1] = {9};
int bridge3_sections[1] = {10};
int interlude_sections[1] = {15};
int interlude2_sections[2] = {16,17};
int outro_sections[1] = {21};
int outro2_sections[4] = {22,23,24,25};
int outro3_sections[1] = {26};

// INTRO
         const int PROGMEM intro1_roof_beat[32] = {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0};
  const int PROGMEM intro1_fence_right_beat[32] = {1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0};
   const int PROGMEM intro1_fence_left_beat[32] = {0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,0,1};
       const int PROGMEM intro1_window_beat[32] = {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0};
      const int PROGMEM intro1_walkway_beat[32] = {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0};
       const int PROGMEM intro1_panel1_beat[32] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1};
       const int PROGMEM intro1_panel2_beat[32] = {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0};
       const int PROGMEM intro1_panel3_beat[32] = {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0};


       const int PROGMEM intro2_roof_beat[32] = {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0};
const int PROGMEM intro2_fence_right_beat[32] = {1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1};
 const int PROGMEM intro2_fence_left_beat[32] = {0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0};
     const int PROGMEM intro2_window_beat[32] = {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0};
    const int PROGMEM intro2_walkway_beat[32] = {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0};
     const int PROGMEM intro2_panel1_beat[32] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0};
     const int PROGMEM intro2_panel2_beat[32] = {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0};
     const int PROGMEM intro2_panel3_beat[32] = {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1};


       const int PROGMEM chorus1_roof_beat[32] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0};
const int PROGMEM chorus1_fence_right_beat[32] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1};
 const int PROGMEM chorus1_fence_left_beat[32] = {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,0,0};
     const int PROGMEM chorus1_window_beat[32] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,0,1,0,0,0,0,0};
    const int PROGMEM chorus1_walkway_beat[32] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0};
     const int PROGMEM chorus1_panel1_beat[32] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,1};
     const int PROGMEM chorus1_panel2_beat[32] = {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,0,1,0};
     const int PROGMEM chorus1_panel3_beat[32] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,0,0,0,0,1,0,0};


       const int PROGMEM chorus21_roof_beat[24] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
const int PROGMEM chorus21_fence_right_beat[24] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};
 const int PROGMEM chorus21_fence_left_beat[24] = {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
     const int PROGMEM chorus21_window_beat[24] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};
    const int PROGMEM chorus21_walkway_beat[24] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};
     const int PROGMEM chorus21_panel1_beat[24] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};
     const int PROGMEM chorus21_panel2_beat[24] = {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
     const int PROGMEM chorus21_panel3_beat[24] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};


       const int PROGMEM post_chorus_roof_beat[32] = {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};
const int PROGMEM post_chorus_fence_right_beat[32] = {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};
 const int PROGMEM post_chorus_fence_left_beat[32] = {1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};
     const int PROGMEM post_chorus_window_beat[32] = {1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};
    const int PROGMEM post_chorus_walkway_beat[32] = {1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};
     const int PROGMEM post_chorus_panel1_beat[32] = {1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};
     const int PROGMEM post_chorus_panel2_beat[32] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};
     const int PROGMEM post_chorus_panel3_beat[32] = {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0};

       
       const int PROGMEM post_chorus2_roof_beat[40] = {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const int PROGMEM post_chorus2_fence_right_beat[40] = {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
 const int PROGMEM post_chorus2_fence_left_beat[40] = {1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM post_chorus2_window_beat[40] = {1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0};
    const int PROGMEM post_chorus2_walkway_beat[40] = {1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
     const int PROGMEM post_chorus2_panel1_beat[40] = {1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0};
     const int PROGMEM post_chorus2_panel2_beat[40] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0};
     const int PROGMEM post_chorus2_panel3_beat[40] = {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};


       const int PROGMEM post_chorus3_roof_beat[56] = {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const int PROGMEM post_chorus3_fence_right_beat[56] = {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0};
 const int PROGMEM post_chorus3_fence_left_beat[56] = {1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0};
     const int PROGMEM post_chorus3_window_beat[56] = {1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1};
    const int PROGMEM post_chorus3_walkway_beat[56] = {1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0};
     const int PROGMEM post_chorus3_panel1_beat[56] = {1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0};
     const int PROGMEM post_chorus3_panel2_beat[56] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM post_chorus3_panel3_beat[56] = {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0};


       const int PROGMEM bridge1_roof_beat[32] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
const int PROGMEM bridge1_fence_right_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 const int PROGMEM bridge1_fence_left_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge1_window_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const int PROGMEM bridge1_walkway_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge1_panel1_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge1_panel2_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge1_panel3_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


       const int PROGMEM bridge2_roof_beat[32] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
const int PROGMEM bridge2_fence_right_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 const int PROGMEM bridge2_fence_left_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge2_window_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
    const int PROGMEM bridge2_walkway_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0};
     const int PROGMEM bridge2_panel1_beat[32] = {0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0};
     const int PROGMEM bridge2_panel2_beat[32] = {0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge2_panel3_beat[32] = {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};


       const int PROGMEM bridge3_roof_beat[32] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
const int PROGMEM bridge3_fence_right_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 const int PROGMEM bridge3_fence_left_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge3_window_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
    const int PROGMEM bridge3_walkway_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0};
     const int PROGMEM bridge3_panel1_beat[32] = {0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0};
     const int PROGMEM bridge3_panel2_beat[32] = {0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0};
     const int PROGMEM bridge3_panel3_beat[32] = {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};


       const int PROGMEM interlude_roof_beat[32] = {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1};
const int PROGMEM interlude_fence_right_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 const int PROGMEM interlude_fence_left_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM interlude_window_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const int PROGMEM interlude_walkway_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM interlude_panel1_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM interlude_panel2_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM interlude_panel3_beat[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


       const int PROGMEM interlude2_roof_beat[48] = {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1};
const int PROGMEM interlude2_fence_right_beat[48] = {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0};
 const int PROGMEM interlude2_fence_left_beat[48] = {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0};
     const int PROGMEM interlude2_window_beat[48] = {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0};
    const int PROGMEM interlude2_walkway_beat[48] = {0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0};
     const int PROGMEM interlude2_panel1_beat[48] = {0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1};
     const int PROGMEM interlude2_panel2_beat[48] = {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
     const int PROGMEM interlude2_panel3_beat[48] = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0};


       const int PROGMEM interlude3_roof_beat[52] = {1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1};
const int PROGMEM interlude3_fence_right_beat[52] = {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0};
 const int PROGMEM interlude3_fence_left_beat[52] = {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0};
     const int PROGMEM interlude3_window_beat[52] = {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const int PROGMEM interlude3_walkway_beat[52] = {0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0};
     const int PROGMEM interlude3_panel1_beat[52] = {0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1};
     const int PROGMEM interlude3_panel2_beat[52] = {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};
     const int PROGMEM interlude3_panel3_beat[52] = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};


       const int PROGMEM outro_roof_beat[32] = {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0};
const int PROGMEM outro_fence_right_beat[32] = {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0};
 const int PROGMEM outro_fence_left_beat[32] = {1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0};
     const int PROGMEM outro_window_beat[32] = {1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0};
    const int PROGMEM outro_walkway_beat[32] = {1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0};
     const int PROGMEM outro_panel1_beat[32] = {1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0};
     const int PROGMEM outro_panel2_beat[32] = {1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
     const int PROGMEM outro_panel3_beat[32] = {1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,0,1,0,1,0,1,0};


       const int PROGMEM outro2_roof_beat[28] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
const int PROGMEM outro2_fence_right_beat[28] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0};
 const int PROGMEM outro2_fence_left_beat[28] = {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,0};
     const int PROGMEM outro2_window_beat[28] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0};
    const int PROGMEM outro2_walkway_beat[28] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0};
     const int PROGMEM outro2_panel1_beat[28] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0};
     const int PROGMEM outro2_panel2_beat[28] = {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,1};
     const int PROGMEM outro2_panel3_beat[28] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0};


       const int PROGMEM outro3_roof_beat[33] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
const int PROGMEM outro3_fence_right_beat[33] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
 const int PROGMEM outro3_fence_left_beat[33] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
     const int PROGMEM outro3_window_beat[33] = {0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,1};
    const int PROGMEM outro3_walkway_beat[33] = {0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1};
     const int PROGMEM outro3_panel1_beat[33] = {1,1,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,0,1,0,1};
     const int PROGMEM outro3_panel2_beat[33] = {0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1};
     const int PROGMEM outro3_panel3_beat[33] = {1,1,0,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,1};




void setup() {
  unsigned int ms_per_minute = 1000 * 60;
  MS_per_beat = ms_per_minute / bpm;

  pinMode(PIN_LED_BEAT, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ROOF, OUTPUT);
  pinMode(WINDOW, OUTPUT);
  pinMode(PANEL1, OUTPUT);
  pinMode(PANEL2, OUTPUT);
  pinMode(PANEL3, OUTPUT);
  pinMode(WALKWAY, OUTPUT);
  pinMode(FENCE_LEFT, OUTPUT);
  pinMode(FENCE_RIGHT, OUTPUT);

  pinMode(TRIGGER_PIN, OUTPUT);

  pinMode(ON_PIN, INPUT);
  pinMode(OFF_PIN, INPUT);
  pinMode(AUDIO_PIN, INPUT);
  digitalWrite(TRIGGER_PIN, LOW);    
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(ON_PIN) == HIGH) {
    delay(500);
    if (buttonCounter == 2) {
      buttonCounter = 0;
    } else {
      buttonCounter++;
    }
    resetCounters();
  }
  if (buttonCounter == 0) {
    allOff();
  } else if (buttonCounter == 1) {
    allOn();
  } else {
    doMusic();
  }
}

void doMusic() {
  if (!musicStarted) {
    allOn();
    digitalWrite(TRIGGER_PIN, LOW);
  }
  
  if (!musicStarted && section == 0 && beatCounter == 0) {
      delay(5000);
      ended = false;
      musicStarted = true;
      digitalWrite(TRIGGER_PIN, HIGH);    
      delay(200);
  }
  if (ended) {
    return;
  }
  if (musicStarted) {
    digitalWrite(PIN_LED_BEAT, digitalRead(PIN_LED_BEAT) != HIGH);
    sectionLength = 31;
    if (loopCounter % 2) {
      if (inArray(intro1_sections, section, 1)) {
        Serial.println("intro1");
        int sequences[] = {
          pgm_read_word_near(intro1_roof_beat + beatCounter),
          pgm_read_word_near(intro1_fence_right_beat + beatCounter),
          pgm_read_word_near(intro1_fence_left_beat + beatCounter),
          pgm_read_word_near(intro1_window_beat + beatCounter),
          pgm_read_word_near(intro1_walkway_beat + beatCounter),
          pgm_read_word_near(intro1_panel1_beat + beatCounter),
          pgm_read_word_near(intro1_panel2_beat + beatCounter),
          pgm_read_word_near(intro1_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(intro2_sections, section, 1)) {
        Serial.println("intro2");
        int sequences[] = {
          pgm_read_word_near(intro2_roof_beat + beatCounter),
          pgm_read_word_near(intro2_fence_right_beat + beatCounter),
          pgm_read_word_near(intro2_fence_left_beat + beatCounter),
          pgm_read_word_near(intro2_window_beat + beatCounter),
          pgm_read_word_near(intro2_walkway_beat + beatCounter),
          pgm_read_word_near(intro2_panel1_beat + beatCounter),
          pgm_read_word_near(intro2_panel2_beat + beatCounter),
          pgm_read_word_near(intro2_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(chorus1_sections, section, 4)) {
        Serial.println("chorus1");
        int sequences[] = {
          pgm_read_word_near(chorus1_roof_beat + beatCounter),
          pgm_read_word_near(chorus1_fence_right_beat + beatCounter),
          pgm_read_word_near(chorus1_fence_left_beat + beatCounter),
          pgm_read_word_near(chorus1_window_beat + beatCounter),
          pgm_read_word_near(chorus1_walkway_beat + beatCounter),
          pgm_read_word_near(chorus1_panel1_beat + beatCounter),
          pgm_read_word_near(chorus1_panel2_beat + beatCounter),
          pgm_read_word_near(chorus1_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(chorus21_sections, section, 4)) {
        Serial.println("chorus21");
        sectionLength = 23;
        int sequences[] = {
          pgm_read_word_near(chorus21_roof_beat + beatCounter),
          pgm_read_word_near(chorus21_fence_right_beat + beatCounter),
          pgm_read_word_near(chorus21_fence_left_beat + beatCounter),
          pgm_read_word_near(chorus21_window_beat + beatCounter),
          pgm_read_word_near(chorus21_walkway_beat + beatCounter),
          pgm_read_word_near(chorus21_panel1_beat + beatCounter),
          pgm_read_word_near(chorus21_panel2_beat + beatCounter),
          pgm_read_word_near(chorus21_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(post_chorus_sections, section, 3)) {
        Serial.println("post_chorus");
        int sequences[] = {
          pgm_read_word_near(post_chorus_roof_beat + beatCounter),
          pgm_read_word_near(post_chorus_fence_right_beat + beatCounter),
          pgm_read_word_near(post_chorus_fence_left_beat + beatCounter),
          pgm_read_word_near(post_chorus_window_beat + beatCounter),
          pgm_read_word_near(post_chorus_walkway_beat + beatCounter),
          pgm_read_word_near(post_chorus_panel1_beat + beatCounter),
          pgm_read_word_near(post_chorus_panel2_beat + beatCounter),
          pgm_read_word_near(post_chorus_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(post_chorus2_sections, section, 1)) {
        Serial.println("post_chorus2");
        sectionLength = 39;
        int sequences[] = {
          pgm_read_word_near(post_chorus2_roof_beat + beatCounter),
          pgm_read_word_near(post_chorus2_fence_right_beat + beatCounter),
          pgm_read_word_near(post_chorus2_fence_left_beat + beatCounter),
          pgm_read_word_near(post_chorus2_window_beat + beatCounter),
          pgm_read_word_near(post_chorus2_walkway_beat + beatCounter),
          pgm_read_word_near(post_chorus2_panel1_beat + beatCounter),
          pgm_read_word_near(post_chorus2_panel2_beat + beatCounter),
          pgm_read_word_near(post_chorus2_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(bridge1_sections, section, 1)) {
        Serial.println("bridge1");
        int sequences[] = {
          pgm_read_word_near(bridge1_roof_beat + beatCounter),
          pgm_read_word_near(bridge1_fence_right_beat + beatCounter),
          pgm_read_word_near(bridge1_fence_left_beat + beatCounter),
          pgm_read_word_near(bridge1_window_beat + beatCounter),
          pgm_read_word_near(bridge1_walkway_beat + beatCounter),
          pgm_read_word_near(bridge1_panel1_beat + beatCounter),
          pgm_read_word_near(bridge1_panel2_beat + beatCounter),
          pgm_read_word_near(bridge1_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(bridge2_sections, section, 1)) {
        Serial.println("bridge2");
        int sequences[] = {
          pgm_read_word_near(bridge2_roof_beat + beatCounter),
          pgm_read_word_near(bridge2_fence_right_beat + beatCounter),
          pgm_read_word_near(bridge2_fence_left_beat + beatCounter),
          pgm_read_word_near(bridge2_window_beat + beatCounter),
          pgm_read_word_near(bridge2_walkway_beat + beatCounter),
          pgm_read_word_near(bridge2_panel1_beat + beatCounter),
          pgm_read_word_near(bridge2_panel2_beat + beatCounter),
          pgm_read_word_near(bridge2_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(bridge3_sections, section, 1)) {
        Serial.println("bridge3");
        int sequences[] = {
          pgm_read_word_near(bridge3_roof_beat + beatCounter),
          pgm_read_word_near(bridge3_fence_right_beat + beatCounter),
          pgm_read_word_near(bridge3_fence_left_beat + beatCounter),
          pgm_read_word_near(bridge3_window_beat + beatCounter),
          pgm_read_word_near(bridge3_walkway_beat + beatCounter),
          pgm_read_word_near(bridge3_panel1_beat + beatCounter),
          pgm_read_word_near(bridge3_panel2_beat + beatCounter),
          pgm_read_word_near(bridge3_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(post_chorus3_sections, section, 1)) {
        Serial.println("post_chorus3");
        sectionLength = 55;
        int sequences[] = {
          pgm_read_word_near(post_chorus3_roof_beat + beatCounter),
          pgm_read_word_near(post_chorus3_fence_right_beat + beatCounter),
          pgm_read_word_near(post_chorus3_fence_left_beat + beatCounter),
          pgm_read_word_near(post_chorus3_window_beat + beatCounter),
          pgm_read_word_near(post_chorus3_walkway_beat + beatCounter),
          pgm_read_word_near(post_chorus3_panel1_beat + beatCounter),
          pgm_read_word_near(post_chorus3_panel2_beat + beatCounter),
          pgm_read_word_near(post_chorus3_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(interlude_sections, section, 1)) {
        Serial.println("interlude");
        int sequences[] = {
          pgm_read_word_near(interlude_roof_beat + beatCounter),
          pgm_read_word_near(interlude_fence_right_beat + beatCounter),
          pgm_read_word_near(interlude_fence_left_beat + beatCounter),
          pgm_read_word_near(interlude_window_beat + beatCounter),
          pgm_read_word_near(interlude_walkway_beat + beatCounter),
          pgm_read_word_near(interlude_panel1_beat + beatCounter),
          pgm_read_word_near(interlude_panel2_beat + beatCounter),
          pgm_read_word_near(interlude_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(interlude2_sections, section, 2)) {
        Serial.println("interlude2");
        sectionLength = 47;
        int sequences[] = {
          pgm_read_word_near(interlude2_roof_beat + beatCounter),
          pgm_read_word_near(interlude2_fence_right_beat + beatCounter),
          pgm_read_word_near(interlude2_fence_left_beat + beatCounter),
          pgm_read_word_near(interlude2_window_beat + beatCounter),
          pgm_read_word_near(interlude2_walkway_beat + beatCounter),
          pgm_read_word_near(interlude2_panel1_beat + beatCounter),
          pgm_read_word_near(interlude2_panel2_beat + beatCounter),
          pgm_read_word_near(interlude2_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(outro_sections, section, 1)) {
        Serial.println("outro");
        int sequences[] = {
          pgm_read_word_near(outro_roof_beat + beatCounter),
          pgm_read_word_near(outro_fence_right_beat + beatCounter),
          pgm_read_word_near(outro_fence_left_beat + beatCounter),
          pgm_read_word_near(outro_window_beat + beatCounter),
          pgm_read_word_near(outro_walkway_beat + beatCounter),
          pgm_read_word_near(outro_panel1_beat + beatCounter),
          pgm_read_word_near(outro_panel2_beat + beatCounter),
          pgm_read_word_near(outro_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(outro2_sections, section, 4)) {
        Serial.println("outro2");
        sectionLength = 27;
        int sequences[] = {
          pgm_read_word_near(outro2_roof_beat + beatCounter),
          pgm_read_word_near(outro2_fence_right_beat + beatCounter),
          pgm_read_word_near(outro2_fence_left_beat + beatCounter),
          pgm_read_word_near(outro2_window_beat + beatCounter),
          pgm_read_word_near(outro2_walkway_beat + beatCounter),
          pgm_read_word_near(outro2_panel1_beat + beatCounter),
          pgm_read_word_near(outro2_panel2_beat + beatCounter),
          pgm_read_word_near(outro2_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      if (inArray(outro3_sections, section, 1)) {
        Serial.println("outro3");
        sectionLength = 32;
        int sequences[] = {
          pgm_read_word_near(outro3_roof_beat + beatCounter),
          pgm_read_word_near(outro3_fence_right_beat + beatCounter),
          pgm_read_word_near(outro3_fence_left_beat + beatCounter),
          pgm_read_word_near(outro3_window_beat + beatCounter),
          pgm_read_word_near(outro3_walkway_beat + beatCounter),
          pgm_read_word_near(outro3_panel1_beat + beatCounter),
          pgm_read_word_near(outro3_panel2_beat + beatCounter),
          pgm_read_word_near(outro3_panel3_beat + beatCounter)
        };
        runSequences(sequences);
      }
      Serial.println(beatCounter);
      if (beatCounter == sectionLength) {
        beatCounter = 0;
        section++;
      } else {
        beatCounter++;
      }
      if (section == 26 && beatCounter == sectionLength) {
        allOn();
        resetCounters();
        delay(120000);
      }
    } else {
      if (section == 26) {
        allOn();
      } else {
        allOff();
      }
    }
    
    loopCounter++;
    delay(MS_per_beat);
  }
}

void doRandomLights() {
  unsigned int ms_per_minute = 1000 * 60;
  MS_per_beat = ms_per_minute / bpm;

  randomSeed(analogRead(0));
  for (int channelIndex = 0; channelIndex < CHANNEL_COUNT; channelIndex++) {
    int randNumber = random(255);
    randNumber = map(randNumber, 0, 255, 255, 0);
    analogWrite(channels[channelIndex], randNumber);
  }
  delay(MS_per_beat/2);
}

void allOn() {
  for (int channelIndex = 0; channelIndex < CHANNEL_COUNT; channelIndex++) {
    digitalWrite(channels[channelIndex], HIGH);
  }
}

void allOff() {
  for (int channelIndex = 0; channelIndex < CHANNEL_COUNT; channelIndex++) {
    digitalWrite(channels[channelIndex], LOW);
  }
}

void powerOnSelfTest() {
  Serial.println("powerOnSelfTest");
  for (int channelIndex = 0; channelIndex < CHANNEL_COUNT; channelIndex++) {
    analogWrite(channels[channelIndex], 0); // turn on one channel at a time
    delay(100);
    analogWrite(channels[channelIndex], 255);
  }
  allOn();
}

void runSequences(int sequences[]) {
  for (int channelIndex = 0; channelIndex < CHANNEL_COUNT; channelIndex++) {
    if (sequences[channelIndex] == 0) {
      digitalWrite(channels[channelIndex], LOW);
    } else {
      digitalWrite(channels[channelIndex], HIGH);
    }
  }
}


boolean inArray(int array[], int element, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    if (array[i] == element) {
      return true;
    }
  }
  return false;
}

void resetCounters() {
  ended = true;
  sectionLength = 32;
  musicStarted = false;
  beatCounter = 0;
  digitalWrite(TRIGGER_PIN, LOW);
  loopCounter = 0;
  section = 0;
}