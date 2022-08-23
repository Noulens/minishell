<!-- Task List -->
## TNO
* Execute on multipipe :
	* [...] Je suis en train de faire une boucle pour executer les cmd multiples en creant autant de pipe que necessaire et en utilisant execve
		* pour le moment j'arrive a avoir autant de de process que de commande et le parent ultime attend la fin de chacun d'eux: ./test "echo yo" "echo -n fuu" "ls -la" "echo test" sans leak et sans erreur
		* j'implemente le piping en boucle : while (i < nb_cmd) {pipe(end[i])} ...

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
	* [ ] ctrl-C
	* [ ] ctrl-D
	* [ ] ctrl-\
* Divers
	* [x] welcome msg en ascii
	* [ ] $? -> faire une variable int qui enregistre la valeur de retour du dernier pipe
		* le parent recoit le code d'exit du child, a placer dans cm->exec_ret