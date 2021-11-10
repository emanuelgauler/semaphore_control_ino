using red_light_pin     = int;
using yellow_light_pin  = int;
using green_light_pin   = int;
struct semaphore {
    semaphore(
      red_light_pin const&,
      yellow_light_pin const&,
      green_light_pin const&
    );

    void switch_on_red_light();
    void switch_off_red_light();
    void switch_on_yellow_light();
    void switch_off_yellow_light();
    void switch_on_green_light();
    void switch_off_green_light();

  private:
    red_light_pin     red_light;
    yellow_light_pin  yellow_light;
    green_light_pin   green_light;
};

int const SEMAPHORES_COUNT {
  4
};
semaphore semaphores[SEMAPHORES_COUNT] = {
  semaphore ( 4, 3, 2 ),
  semaphore ( 7, 6 , 5 ),
  semaphore ( 10, 9, 8 ),
  semaphore ( 13, 12, 11 )/**/
};

void setup() {
  for ( auto i = 2; i <= 13; ++i )
    pinMode( i, OUTPUT );

  for ( semaphore s : semaphores )
  {
    s.switch_on_red_light();
    s.switch_off_yellow_light();
    s.switch_off_green_light();
  }
}

void loop() {
  delay( 2000 );
  for ( auto s : semaphores ) {
    s.switch_on_yellow_light();
    delay( 400 );

    s.switch_off_red_light();
    s.switch_off_yellow_light();
    s.switch_on_green_light();
    delay( 1000 );
    s.switch_on_yellow_light();
    delay( 400 );
    s.switch_on_red_light();
    s.switch_off_yellow_light();
    s.switch_off_green_light();
    delay( 600 );
  }
}


semaphore::semaphore(
  red_light_pin const&rp,
  yellow_light_pin const&yp,
  green_light_pin const&gp ):
  red_light     { rp },
  yellow_light  { yp },
  green_light   { gp }
{}

void semaphore::switch_on_red_light() {
  digitalWrite( red_light, HIGH );
}
void semaphore::switch_off_red_light() {
  digitalWrite( red_light, LOW );
}
void semaphore::switch_on_yellow_light() {
  digitalWrite( yellow_light, HIGH );
}
void semaphore::switch_off_yellow_light() {
  digitalWrite( yellow_light, LOW );
}
void semaphore::switch_on_green_light() {
  digitalWrite( green_light, HIGH );
}
void semaphore::switch_off_green_light() {
  digitalWrite( green_light, LOW );
}
