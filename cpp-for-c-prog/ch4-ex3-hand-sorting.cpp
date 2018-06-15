#include <iostream>
using namespace std;

class zootSuit {
public:
  enum suit { clubs, diamonds, hearts, spades };
  suit getSuit() { return s; }
  void setSuit(suit s) { this->s = s; }
  void print();
private:
  suit s;
};

void zootSuit::print() {
  switch(s) {
    case 0 : cout << "clubs"; break;
    case 1 : cout << "diamonds"; break;
    case 2 : cout << "hearts"; break;
    case 3 : cout << "spades"; break;
  }
}

class pips {
public:
  void assign(int n) { p = n % 13 + 1; }
  int getPip() { return p; }
  void print() { cout << p; }
private:
  int p;
};

class card {
public:
  zootSuit s;
  pips p;
  void assign(int n) {
    cd = n;
    s.setSuit(static_cast<zootSuit::suit>(n / 13));
    p.assign(n);
  }
private:
  int cd; // A cd is from 0 to 51
};

class deck {
public:
  void initDeck();
  void shuffle();
  void deal(int, int, card*);
  void printDeck();
private:
  card d[52];
};

void deck::initDeck() {
  for (int i = 0; i < 52; ++i) {
    d[i].assign(i);
  }
}

void deck::shuffle() {
  for (int i = 0; i < 52; ++i) {
    int k = i + (rand() % (52 - i));
    card t = d[i]; // Swap cards
    d[i] = d[k];
    d[k] = t;
  }
}

void deck::deal(int n, int pos, card* hand) {
  for (int i = pos; i < pos + n; ++i) {
    hand[i - pos] = d[i];
  }
}

void reassign(card *ci, card *cj) {
  card temp;

  temp = *ci;
  *ci = *cj;
  *cj = temp;
}

void sort(card cards[], int n) {
  int i, j;

  for (i = 0; i < n - 1; ++i) {
    for (j = i + 1; j < n; ++j) {
      if (cards[i].p.getPip() < cards[j].p.getPip()) {
        reassign(&cards[i], &cards[j]);
      }
    }
  }
}

int main() {
  card one_hand[9];
  deck dk;
  int i, k;
  int ndeal, nc, nhand;

  do {
    cout << "\nEnter no. cards in a hand (5-9): ";
    cin >> nc;
  } while (nc < 5 || nc > 9);

  nhand = 52 / nc;

  cout << "\nEnter no. of hands to deal: ";
  cin >> ndeal;

  srand(time(NULL));

  dk.initDeck();

  for (k = 0; k < ndeal; k += nhand) {
    if ((nhand + k) > ndeal) {
      nhand = ndeal - k;
    }
    dk.shuffle();
    cout << "\nShufflin\'...";
    dk.deal(nc, i, one_hand); // Deal next hand
    cout << "\nGroovy. One hand looks like so:\n";
    for (i = 0; i < nc; i++) {
      cout << "| ";
      one_hand[i].p.print();
      cout << " of ";
      one_hand[i].s.print();
      cout << " |";
    }
    cout << "\n";

    cout << "\nNow let's sort that hand by pip count...\n";
    sort(one_hand, nc);

    cout << "\nThat sorted hand looks like so:\n";
    for (i = 0; i < nc; i++) {
      cout << "| ";
      one_hand[i].p.print();
      cout << " of ";
      one_hand[i].s.print();
      cout << " |";
    }
    cout << "\n";
  }
}
