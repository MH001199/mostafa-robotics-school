const uint8_t PIEZO_PIN = 7;

struct Note {
  unsigned int hz;
  unsigned int ms;
};

// A short original phrase. A zero frequency represents a rest.
const Note melody[] = {{262, 200}, {330, 200}, {392, 300},
                       {0, 120}, {440, 200}, {392, 400}};

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
  for (const Note &note : melody) {
    if (note.hz > 0) {
      tone(PIEZO_PIN, note.hz, note.ms);
    } else {
      noTone(PIEZO_PIN);
    }
    delay(note.ms + 40);
  }
}

void loop() {
  // The melody plays once per reset.
}
