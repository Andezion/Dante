use regex::Regex;

fn main() 
{
    let mut phone_input = String::new();
    let mut code_input = String::new();

    println!("Podaj numer telefonu: ");
    std::io::stdin().read_line(&mut phone_input).expect("Nieprawidłowy numer");
    let phone_input = phone_input.trim();

    println!("Podaj numer kierunkowy: ");
    std::io::stdin().read_line(&mut code_input).expect("Nieprawidłowy kod");
    let code_input = code_input.trim();

    let re_code = Regex::new(r"^\d{2}$").unwrap();
    let re_phone = Regex::new(r"^(\d{3})-(\d{2})-(\d{2})$").unwrap();

    if re_code.is_match(code_input) 
    {
        if let Some(caps) = re_phone.captures(phone_input) 
        {
            let part1 = &caps[1];
            let part2 = &caps[2];
            let part3 = &caps[3];
            println!("({}) {}-{}-{}", code_input, part1, part2, part3);
        } 
        else 
        {
            println!("Nieprawidłowy format numeru telefonu!");
        }
    } 
    else 
    {
        println!("Nieprawidłowy numer kierunkowy!");
    }
}
