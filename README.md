<!-- Task List -->
## TO DO
* TO-DO
	* [x] Refaire la variable globale pour qu'elle soit égale au minishell
	* [x] Modifier la gestion des signaux suite à la modif de la variable globale
	* [ ] Trier le env par valeur ascii -> TNO finir utils1.c
	* [x] export AAA -> declare -x AAA
	* [ ] export A="ls -l" ; $A -> execute ls -l -> TNO faire ft_strchr(' ') si non NULL -> split et refaire char **
	* [ ] ligne 21 et 107 execute.c -> supprimer getenv pour PATH et prendre env ms à la place

* Mode commande
	* [x] implementer le mode command

* Execute on multipipe :
	* [x] Boucle pour executer les cmd multiples en creant autant de pipe que necessaire et en utilisant execve
	* [x] Gestion des built-in avant execve
	* [x] /!\ redirection quand : echo foo >> infile | grep foo il faut le resultat dans infile et pas dans grep !!
	* [x] /!\ lexer: gérer les espaces en envoyant un élément à la fois par maillon de liste tok (ex: echo -n fuu  -> echo -> -n -> fuu au lieu de -> echo -n fuu)
	* [x] /!\ parsing: faire une LL pour gérer les espaces
	* [x] /!\ echo "$" -> doit afficher $
	* [x] $$ a gerer ? -> non

* Here_doc :
	* [x] Here_doc : ok.

* Garbage collector :
	* [x] int	gb_c(t_list **gb, void *content, void **content2)  : liste chainee avec un lst_add_back du pointeur * ou du pointeur ** ou NULL a chaque malloc et un free final de la lst a la fin. Inutile d'y ajouter les ptr des que l'on sait qu'ils vont etre free dans la foulee.

* Implement :
	* [x] echo et l’option -n
	* [x] cd uniquement avec un chemin relatif ou absolu et FAIRE HOME
	* [x] pwd sans aucune option
	* [x] export sans aucune option
	* [x] unset sans aucune option
	* [x] env sans aucune option ni argument
	* [x] exit sans aucune option
* Signaux :
	* [x] ctrl-C OK sans leaks : write(1, "\n", 1); rl_on_new_line(); rl_redisplay();
	* [x] ctrl-D OK sans leaks
	* [x] ctrl-\ OK
* Divers
	* [x] welcome msg en ascii
	* [x] $? -> faire une variable int qui enregistre la valeur de retour du dernier pipe
		* le parent recoit le code d'exit du child, a placer dans cm->exec_ret
