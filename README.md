<!-- Task List -->
## TNO
* Execute on multipipe :
	* [x] Boucle pour executer les cmd multiples en creant autant de pipe que necessaire et en utilisant execve

* Here_doc :
	* [ ] Here_doc : prototype ok, il faut activer ou désactivier le flag manuellement a ce stade. << LIMITER :token a chercher, qui active le flag.

* Garbage collector :
	* [x] int	gb_c(t_list **gb, void *content, void **content2)  : liste chainee avec un lst_add_back du pointeur * ou du pointeur ** ou NULL a chaque malloc et un free final de la lst a la fin. Inutile d'y ajouter les ptr des que l'on sait qu'ils vont etre free dans la foulee.
* Implement :
	* [x] echo et l’option -n
	* [ ] cd uniquement avec un chemin relatif ou absolu
	* [x] pwd sans aucune option
	* [ ] export sans aucune option
	* [ ] unset sans aucune option
	* [x] env sans aucune option ni argument
	* [ ] exit sans aucune option
* Signaux :
	* [x] ctrl-C OK sans leaks : write(1, "\n", 1); rl_on_new_line(); rl_redisplay();
	* [x] ctrl-D OK sans leaks
	* [ ] ctrl-\ à tester
* Divers
	* [x] welcome msg en ascii
	* [ ] $? -> faire une variable int qui enregistre la valeur de retour du dernier pipe
		* le parent recoit le code d'exit du child, a placer dans cm->exec_ret