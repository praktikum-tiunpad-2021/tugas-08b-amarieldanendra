#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T data;
  int priority;
  Element *next;
  Element(T data, int priority){
    this -> data = data;
    this -> priority = priority;
    this -> next = nullptr;
  }
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T>head;
  ElementPtr<T>tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T>QNew;
  QNew.head = nullptr;
  QNew.tail = nullptr;
  return QNew;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T>QNew = new Element<T>(value, priority);
  if(q.head == nullptr){
    q.head = QNew;
    q.tail = QNew;
  } else {
    ElementPtr<T>pHelp = q.head;
    ElementPtr<T>pHelp2 = nullptr;
    while(pHelp->priority >= priority&& pHelp->next != nullptr){
      pHelp2 = pHelp;
      pHelp = pHelp->next;
    }
    if (pHelp == q.head && pHelp->priority <priority){
      QNew->next = pHelp;
      q.head = QNew;
    }
    else if (pHelp == q.tail && pHelp->priority > priority){
      pHelp->next = QNew;
      q.tail = QNew;
    }
    else {
      pHelp2->next = QNew;
      QNew->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T>deleteElmt;
  if (q.head == nullptr && q.tail == nullptr){
    deleteElmt = nullptr;
  } 
  else if (q.head->next == nullptr){
    deleteElmt = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } 
  else {
    deleteElmt = q.head;
    q.head = q.head->next;
    deleteElmt->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
