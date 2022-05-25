class Rock {
  // Member Variables
  int x, y, diam, health, speed, rand, randDiam;
  PImage rock;

  // Constructor
  Rock(int x, int y) {
    this.x = x;
    this.y = y;
    speed = int(random(5, 8 ));
    diam = int(random(5, 10));
    health = diam * 10;
    rand = int(random(6));
    if (rand == 0) {
      rock = loadImage("rock_0.png");
    } else if (rand == 1) {
      rock = loadImage("rock_1.png");
    } else if (rand == 2) {
      rock = loadImage("rock_2.png");
    } else if (rand == 3) {
      rock = loadImage("rock_3.png");
    } else if (rand == 4) {
      rock = loadImage("rock_4.png");
    } else {
      rock = loadImage("rock_5.png");
    }
    randDiam = int(random(2));
  }
  // Member Methods
  void display() {
    //if (randDiam == 2) {
    //  rock.resize(48, 48);
    //} else if (randDiam == 1) {
    //  rock.resize(64, 64);
    //} else {
    //  rock.resize(80, 80);
    //}
    rock.resize(64, 64);
    image(rock, x, y);
    fill(200);
    textAlign(CENTER, CENTER);
    textSize(16);
    text(health, x, y-5);
  }

  void move() {
    y += speed;
  }

  boolean reachedBottom() {
    if (y > height+50) {
      return true;
    } else {
      return false;
    }
  }

  boolean intersect(Ship s) {
    float distance = dist(x, y, s.x, s.y);
    if (distance < 30) {
      return true;
    } else {
      return false;
    }
  }
}
