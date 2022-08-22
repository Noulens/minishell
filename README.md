<!-- Task List -->
## TNO
* Execute on multipipe :
	* Je suis en train de faire une boucle pour executer les cmd multiples en creant autant de pipe que necessaire et en utilisant execve
* Garbage collector :
	* liste chainee avec un lst_add_back du pointeur a chaque malloc et un free final de la lst a la fin.
	* Inutile d'y ajouter les ptr des que l'on sait qu'ils vont etre free dans la foulee.
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
	* [ ] $? -> faire une variable static int qui enregistre la valeur de retour du dernier pipe