function Id(name) {
    return document.getElementById(name);
}

function DTag(name) {
    return document.getElementsByTagName(name);
}

function Tag(object, name) {
    return object.getElementsByTagName(name);
}

function Cls(name) {
    return document.getElementsByClassName(name);
}

function Sti(name) {
    return Id(name).style;
}

function SCls(name) {
    return Cls(name)[0].style;
}

function crE(name) {
    return document.createElement(name);
}