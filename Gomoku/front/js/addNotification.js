function addNotification(text) {
  const notification = document.querySelector('.notification');
  const p = newElem('p');
  p.innerHTML = text;
  notification.insertBefore(p, notification.firstChild);
}
