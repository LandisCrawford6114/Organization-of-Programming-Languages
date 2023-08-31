fn main() 
{
    println!("Hello World");

    let mut x = 8;
    println!("{}", x);
    x = 9;
    println!("{}", x);

    /*
    for i in 1..=100
    {
        if i % 2 == 0
        {
            println!("World");
        }
        else
        {
            print!("Hello ");
        }
    }
    */

    println!("{}", addition(2,3));

    let a: (i32, char) = (7,'a');
    println!("{:?}", a);

    let b = ((1,2,3),(4,5),6);
    println!("{:?}", b);

    let c: [i32;9] = [1,2,3,4,5,6,7,8,9];
    for i in 0..9
    {
        print!("{}",c[i]);
    }
    println!("");
}

fn addition(x: i32, y: i32) -> i32
{
    x + y
}