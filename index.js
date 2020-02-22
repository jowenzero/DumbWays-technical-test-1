function ProfileSpawn() {
    var para = document.createElement("P");
    var img = document.createElement("IMG");
    var button = document.createElement("BUTTON");

    var name = document.createTextNode("Name");
    var space = document.createTextNode("     | ");
    var hobby = document.createTextNode("Hobby");

    para.className = "monospace";
    para.appendChild(name);
    para.appendChild(space);
    para.appendChild(hobby);

    img.src = "https://cdn.pixabay.com/photo/2015/10/05/22/37/blank-profile-picture-973460_960_720.png"
    img.height = "150";
    img.width = "150";
    button.innerText = "Detail";
    button.className = "button";

    document.body.appendChild(para);
    document.body.appendChild(img);
    document.body.appendChild(button);
  }