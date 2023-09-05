//https://dev.to/siddharthshyniben/building-a-compiler-working-on-the-tokenizer-3h6a
fn main() 
{
    let mut b = true;
    while b{
        println!("Would you like to play my game?");
        let a: String = input().to_string();
        if a == "yes".to_string()
        {
            println!("Congrats you win");
            b = false;
        }
        else if a == "no".to_string()
        {
            println!("What a dweeb, you lose");
            b = false;
        }
        else
        {
            println!("This is a simple yes or no question stop trying to be fancy.");
        }
    }
}

fn input() -> String {
    use std::io;
    let mut user_in = String::new();
    io::stdin().read_line(&mut user_in).expect("failed to readline");
    let (first, _last) = user_in.split_at(user_in.len()-1);
    return first.to_string();
}