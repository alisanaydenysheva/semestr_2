
const links = document.querySelectorAll('.header-menu__item a')
links.forEach((element) => {
	element.addEventListener('click', (event) =>	{
		event.preventDefault()
	
		const id = element.getAttribute('href').substring(1);
		const section = document.getElementById(id);
		console.log(section);		
		if (section) {
			section.scrollIntoView({
				behavior: 'smooth',
				block: 'start'
			});	
		}else{
			console.log('нет');
		}
	})
})
