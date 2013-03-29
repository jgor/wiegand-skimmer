int wiegand[64];
int wiegand_idx, waiting;

void decode35() {
  int i;
  long facility = 0, card = 0;
  
  for (i = 2; i < 14; i++) {
    facility |= (wiegand[i] << (13-i));
  }
  
  for (i = 14; i < 34; i++) {
    card |= ((long)wiegand[i] << (33-i));
  }
  
  Serial.print("F=");
  Serial.print(facility);
  Serial.print(" C=");
  Serial.println(card);
  
}

void decode26() {
  int i;
  long facility = 0, card = 0;
  
  for (i = 1; i < 9; i++) {
    facility |= (wiegand[i] << (8-i));
  }
  
  for (i = 9; i < 25; i++) {
    card |= ((long)wiegand[i] << (24-i));
  }
  
  Serial.print("F=");
  Serial.print(facility);
  Serial.print(" C=");
  Serial.println(card);
  
}

void decode(int len) { 
  switch(len) {
    case 26: decode26(); break;
    case 35: decode35(); break;
  }
}

void data0() {
  wiegand[wiegand_idx++] = 0;
  waiting = 10000;
}

void data1() {
  wiegand[wiegand_idx++] = 1;
  waiting = 10000;
}

void setup() {
  wiegand_idx = 0;

  attachInterrupt(0, data0, FALLING);
  attachInterrupt(1, data1, FALLING);

  Serial.begin(9600);
}

void loop() {
  if (!waiting && wiegand_idx) {
    decode(wiegand_idx);
    wiegand_idx = 0;
  }
  else if (waiting) {
    waiting--;
  }
}


