Ship s1;
ArrayList<Rock> rocks = new ArrayList<Rock>();
ArrayList<Powerup> powerups = new ArrayList<Powerup>();
ArrayList<Laser> lasers = new ArrayList<Laser>();
ArrayList<Star> stars = new ArrayList<Star>();
Timer rockTimer, puTimer;
int score, level, rockTime, puTime;
boolean play;

void setup() {
  size(750, 1000);
  s1 = new Ship("ship_", 8);
  score = 0;
  level = 1;
  rockTime = 1000;
  rockTimer = new Timer(rockTime);
  rockTimer.start();
  puTime = 25000;
  puTimer = new Timer(puTime);
  puTimer.start();
}

void draw() {
  background(0);
  noCursor();

  if (!play) {
    startScreen();
  } else {
    
    if(frameCount % 1000 == 10) {
      level++;
      rockTime += 100;
    }

    stars.add(new Star());
    for (int i = 0; i < stars.size(); i++) {
      Star star = stars.get(i);
      star.display();
      star.move();
      if (star.reachedBottom()) {
        stars.remove(star);
      }
    }

    if (rockTimer.isFinished()) {
      rocks.add(new Rock(int(random(20, width-20)), -100));
      rockTimer.start();
    }

    if (puTimer.isFinished()) {
      powerups.add(new Powerup(int(random(20, width-20)), -100));
      puTimer.start();
    }

    for (int i = 0; i < rocks.size(); i++) {
      Rock rock = rocks.get(i);
      rock.display();
      rock.move();
      if (rock.intersect(s1)) {
        rocks.remove(rock);
        s1.health -= 25;
      }
      if (rock.reachedBottom()) {
        rocks.remove(rock);
        s1.health -= 10;
      }
    }

    for (int i = 0; i < powerups.size(); i++) {
      Powerup pu = powerups.get(i);
      pu.display();
      pu.move();
      if (pu.intersect(s1)) {
        if (pu.type == 't') {
          s1.turret++;
        } else if (pu.type == 'h') {
          s1.health += 50;
        } else if (pu.type == 's') {
          s1.health += 50;
        }
        powerups.remove(pu);
      }
      if (pu.reachedBottom()) {
        powerups.remove(pu);
        s1.health -= 10;
      }
    }

    for (int i = 0; i < lasers.size(); i++) {
      Laser laser = lasers.get(i);
      for (int j = 0; j < rocks.size(); j++) {
        Rock rock = rocks.get(j);
        if (laser.intersect(rock)) {
          //rock.resize(rock.diam-10, rock.diam-10);
          score += rock.health;
          lasers.remove(laser);
          rock.health -= 15;
          if (rock.health < 10) {
            rocks.remove(rock);
          }
        }
      }
      laser.display();
      laser.move();
      if (laser.reachedTop()) {
        lasers.remove(laser);
      }
    }

    s1.display(mouseX, mouseY);

    infoPanel();

    if (s1.health <= 0) {
      gameOver();
      noLoop();
    }
  }
}

void infoPanel() {
  fill(0);
  stroke(255);
  rectMode(CORNER);
  rect(10, 10, width/3, 45, 5);
  fill(255);
  textSize(14);
  textAlign(LEFT);
  text("Score: " + score + "\nHealth: " + s1.health, 15, 25);
  noStroke();
}

void startScreen() {
  background(0);
  textAlign(CENTER);
  fill(255);
  textSize(46);
  text("SPACE GAME", width/2, (height/2) - 40);
  textSize(23);
  text("CLICK ANYWHERE TO START", width/2, (height/2)+40);
  if (mousePressed) {
    play = true;
  }
}

void gameOver() {
  background(0);
  textAlign(CENTER);
  fill(255);
  textSize(46);
  text("GAME OVER", width/2, (height/2) - 40);
  textSize(23);
  text("FINAL SCORE: " + score, width/2, height/2 + 20);
}

void ticker() {
}

void mousePressed() {
  if (s1.turret == 1) {
    if (s1.fireRight) {
      lasers.add(new Laser(s1.x-6, s1.y));
      s1.fireRight = false;
    } else if (!s1.fireRight) {
      lasers.add(new Laser(s1.x+6, s1.y));
      s1.fireRight = true;
    }
  } else if (s1.turret == 2) {
    lasers.add(new Laser(s1.x-6, s1.y));
    lasers.add(new Laser(s1.x+6, s1.y));
  }
}

void keyPressed() {
  if (keyPressed) {
    if (key == ' ') {
      if (s1.turret == 1) {
        if (s1.fireRight) {
          lasers.add(new Laser(s1.x-6, s1.y));
          s1.fireRight = false;
        } else if (!s1.fireRight) {
          lasers.add(new Laser(s1.x+6, s1.y));
          s1.fireRight = true;
        }
      } else if (s1.turret == 2) {
        lasers.add(new Laser(s1.x-6, s1.y));
        lasers.add(new Laser(s1.x+6, s1.y));
      }
    }
  }
}
