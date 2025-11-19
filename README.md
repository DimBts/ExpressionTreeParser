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

+ - * / %

## Βασική Λειτουργία
Ο χρήστης εισάγει μία παράσταση, για παράδειγμα:

(4*(2+3))

markdown
Copy code

Το πρόγραμμα:

1. Ελέγχει την εγκυρότητα της εισόδου  
2. Δημιουργεί το δέντρο έκφρασης  
3. Παρέχει επιλογές μέσω μενού:

1.Enter expression

2.Calculate expression

3.Display prefix form

4.Display postfix form

5.Print binary tree

6.Exit


---

## 📂 Δομή Κώδικα

### Σημαντικές Συναρτήσεις

| Συνάρτηση | Λειτουργία |
|----------|------------|
| `parseExpression()` | Δημιουργεί το expression tree από infix έκφραση |
| `evaluate()` | Υπολογίζει την τιμή της παράστασης |
| `printPrefix()` | Εκτυπώνει το δέντρο σε prefix μορφή |
| `printPostfix()` | Εκτυπώνει το δέντρο σε postfix μορφή |
| `printTree()` | Εκτυπώνει το δυαδικό δέντρο |
| `validateExpression()` | Ελέγχει αν η είσοδος είναι σωστή μαθηματική παράσταση |

---

## Οδηγίες Μεταγλώττισης

### GCC (Linux / macOS)
```bash
gcc -o expression_tree main.c
./expression_tree
### Windows (MinGW)
bash
Copy code
gcc main.c -o expression_tree.exe
expression_tree.exe
