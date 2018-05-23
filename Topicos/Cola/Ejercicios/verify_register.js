function validar() {
	var name, last_name, email, user_name, password, expression;
	name = document.getElementById('name').value;
	last_name = document.getElementById('last_name').value;
	user_name = document.getElementById('user_name').value;
	email = document.getElementById('email').value;
	password = document.getElementById('password').value;

	if (name==="" || last_name==="" || user_name===""
		|| email==="" || password===""){
		alert("Todos los campos deben estar completos");
		return false;
	}
}