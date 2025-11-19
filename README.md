# ExpressionTreeParser
Infix to Postfix or Prefix Convertions and Calculations
## Περιγραφή
Το πρόγραμμα διαβάζει μία αριθμητική παράσταση σε **infix μορφή**, δημιουργεί το αντίστοιχο δέντρο έκφρασης (expression tree) και παρέχει λειτουργίες όπως:

- υπολογισμός της παράστασης  
- εμφάνιση σε **prefix** μορφή  
- εμφάνιση σε **postfix** μορφή  
- εκτύπωση του δυαδικού δέντρου  
- έλεγχος εγκυρότητας της infix έκφρασης  

Το πρόγραμμα υποστηρίζει αριθμούς & τους τελεστές:

"+ - * / %"

## Βασική Λειτουργία
Ο χρήστης εισάγει μία παράσταση, για παράδειγμα:

(4*(2+3))

Το πρόγραμμα:

1. Ελέγχει την εγκυρότητα της εισόδου  
2. Δημιουργεί το δέντρο έκφρασης  
3. Παρέχει επιλογές μέσω μενού:

Enter expression

Calculate expression

Display prefix form

Display postfix form

Print binary tree

Exit


---

## Παραδείγματα Χρήσης

![Παράδειγμα εισόδου](/images/ExpressionTreeParser3.png)

![1](/images/ExpressionTreeParser4.png)

![2](/images/ExpressionTreeParser5.png)

![3](/images/ExpressionTreeParser6.png)

![4](/images/ExpressionTreeParser8.png)

![5](/images/ExpressionTreeParser2.png)

## Σημειώσεις

Η παράσταση πρέπει να είναι πλήρως παρενθετοποιημένη (όπως απαιτεί ο parser).

Το πρόγραμμα δεν επιτρέπει μη αριθμητικούς χαρακτήρες και μη ισορροπημένες παρενθέσεις.

Σε λάθος είσοδο, εμφανίζεται μήνυμα σφάλματος και ζητείται νέα έκφραση.


## Δομή Κώδικα

### Σημαντικές Συναρτήσεις
`parseExpression()` | Δημιουργεί το expression tree από infix έκφραση
`evaluate()` | Υπολογίζει την τιμή της παράστασης
`printPrefix()` | Εκτυπώνει το δέντρο σε prefix μορφή
`printPostfix()` | Εκτυπώνει το δέντρο σε postfix μορφή
`printTree()` | Εκτυπώνει το δυαδικό δέντρο
`validateExpression()` | Ελέγχει αν η είσοδος είναι σωστή μαθηματική παράσταση

---

## Οδηγίες Μεταγλώττισης

### GCC (Linux / macOS)
gcc -o expression_tree main.c
./expression_tree

### Windows (MinGW)
gcc main.c -o expression_tree.exe
expression_tree.exe
