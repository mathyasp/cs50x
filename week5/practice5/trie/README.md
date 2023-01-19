---
files: [trie.c]
url: https://cdn.cs50.net/2022/fall/labs/5/trie/README.md
window: [terminal]
---

# Trie

## Learning Goals

* Learn more about data structures
* Work with a trie

![puppies](puppies.jpeg)

## Background

Imagine you just rescued a dog and you're deciding on a name. You found a file online with a list of about 150 of the most popular dog names! You are curious as to whether or not the names you are considering are on this list. Since trie's are great for data lookups, we've given you some (almost!) complete code in `trie.c`. There is one function, `check`, which is not yet implemented. Your job is to complete this function.

## Demo

<script async data-autoplay="1" data-cols="100" data-loop="1" data-rows="12" id="asciicast-JukHED1VvaJLFHMJbIvLksgF1" src="https://asciinema.org/a/JukHED1VvaJLFHMJbIvLksgF1.js" async></script>

## Implementation Details

Notice that the trie itself is implemented through the creative use of several `struct`s called `node`. Each `node` in a trie has an array of (potential) children, with size 26—one potential child for each letter of the alphabet! Adding words to this trie, notice that—for every letter in a word—we create a new `node` child whose parent is either the `root` node (for the first letter) or the previous letter (if not the first letter). On the very last letter, we set the `is_word` attribute of the child `node` to `true`. Now, checking if a word is in our trie is as easy as following each letter of that word through our trie. If we get to the final letter and see that `is_word` is true, well, that name is in our trie!

+ Hints
  * You probably want to start by setting a `node` pointer, `cursor` to the `root` of the trie.
  * Iterate through every letter in the argument `word` and, as you do, determine the array index that corresponds to that letter.
  * You can use the index for a letter to check if `children[index]` is a `NULL` pointer, meaning the word does not exist in the trie.
  * If `children[index]` is in fact a node, you can reset `cursor` to this node and check for the next letter in its `children` nodes.
  * Remember that the lookup should be case-insensitive. For instance, `A` and `a` should correspond to 0, `B` and `b` corresponds to 1, etc.
  
## Thought Question

* When might you want to use a trie as a data structure? When might you _not_?

## How to Test Your Code

Your program should behave per the examples below.

```
trie/ $ ./trie dog_names.txt
Check word: Molly
Found!
```

```
trie/ $ ./trie dog_names.txt
Check word: Lucy
Found!
```

```
trie/ $ ./trie dog_names.txt
Check word: Prudence
Not Found.
```

No `check50` for this one!

To evaluate that the style of your code, type in the following at the `$` prompt. 

```
style50 trie.c
```

## How to Submit

No need to submit! This is a practice problem.