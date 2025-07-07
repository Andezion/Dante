struct Student {
    name: [char; 20],
    surname: [char; 40],

    index: i32,

    field: [char; 50],
    faculty: [char; 80],

    year: i32
}

fn checker(letter: & char) -> u8 {
    let array:[char; 6] = ['a', 'e', 'y', 'u', 'i', 'o'];

    if array.contains(letter)
    {
        return 1;
    }

    0
}

fn change_to_string(array: &[char]) -> String {
    array.iter()
        .take_while(|&&c| c != '\0')
        .collect()
}

fn display(p: &Student) {
    let name = change_to_string(&p.name);
    let surname = change_to_string(&p.surname);
    let field = change_to_string(&p.field);
    let faculty = change_to_string(&p.faculty);

    let article = if checker(&p.field[0]) == 1 {
        "an"
    } else {
        "a"
    };

    println!(
        "Your name is: {} {}, index: {}, were {} {} student at the {} in {}",
        name, surname, p.index, article, field, faculty, p.year
    );

    println!();
}

fn helper<const N: usize>(input: &str) -> [char; N] {
    let mut arr = ['\0'; N];
    let chars: Vec<char> = input.chars().collect();

    if chars.len() > N {
        panic!("String too long (max {} chars allowed)", N);
    }

    for (i, c) in chars.into_iter().enumerate() {
        arr[i] = c;
    }

    arr
}

fn read(p: &mut Student) -> &mut Student {
    let mut input: String = String::new();

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let name: String = input.trim().parse().expect("Incorrect parse 1");
    p.name = helper::<20>(&name);

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let surname: String = input.trim().parse().expect("Incorrect parse");
    p.surname = helper::<40>(&surname);

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    p.index = input.trim().parse().expect("Incorrect parse");

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let field: String = input.trim().parse().expect("Incorrect parse");
    p.field = helper::<50>(&field);

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let faculty: String = input.trim().parse().expect("Incorrect parse");
    p.faculty = helper::<80>(&faculty);

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    p.year = input.trim().parse().expect("Incorrect parse");

    p
}

fn set(p: &mut Student, name: String, surname: String,
            index: i32, field: String, faculty: String,
            year: i32) -> &mut Student {
    if name.len() >= 20 || surname.len() >= 40 || field.len() >= 50 ||
        faculty.len() >= 80 || index <= 0 || year <= 0
    {
        panic!("Error in provided data");
    }

    p.name = helper::<20>(&name);
    p.surname = helper::<40>(&surname);
    p.index = index;
    p.field = helper::<50>(&field);
    p.faculty = helper::<80>(&faculty);
    p.year = year;

    p
}

fn main() {
    let mut p1 = Student {
        name: [' '; 20],
        surname: [' '; 40],
        index: 0,
        field: [' '; 50],
        faculty: [' '; 80],
        year: 0,
    };

    set(&mut p1, "Vladyslav".parse().unwrap(), "Grimm".parse().unwrap(),
        245122, "Informatyka".parse().unwrap(), "WEEiA".parse().unwrap(), 2022);

    display(&p1);


    let mut p2 = Student {
        name: [' '; 20],
        surname: [' '; 40],
        index: 0,
        field: [' '; 50],
        faculty: [' '; 80],
        year: 0,
    };
    display(read(&mut p2));
}
