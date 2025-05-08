import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

class SimpleRAG:
    def __init__(self, documents, vocab_size=1000, embedding_dim=128):
        self.documents = documents
        self.vocab_size = vocab_size
        self.embedding_dim = embedding_dim
        self.vectorizer = TfidfVectorizer(max_features=vocab_size)
        self.doc_vectors = self.vectorizer.fit_transform(documents).toarray()
        self.W_gen = np.random.randn(embedding_dim, vocab_size) / np.sqrt(embedding_dim)
        
    def retrieve(self, query, k=3):
        query_vector = self.vectorizer.transform([query]).toarray()
        similarities = cosine_similarity(query_vector, self.doc_vectors)[0]
        top_k_indices = np.argsort(similarities)[-k:][::-1]
        return [self.documents[i] for i in top_k_indices]
    
    def generate(self, context, max_len=20):
        context_vector = self.vectorizer.transform([context]).toarray()[0]
        context_embedding = np.random.randn(self.embedding_dim)
        output = []
        for _ in range(max_len):
            logits = np.matmul(context_embedding, self.W_gen)
            probs = np.exp(logits) / np.sum(np.exp(logits))
            next_token_idx = np.argmax(probs)
            output.append(self.vectorizer.get_feature_names_out()[next_token_idx])
            context_embedding += np.random.randn(self.embedding_dim) * 0.1
        return ' '.join(output)
    
    def forward(self, query):
        retrieved_docs = self.retrieve(query)
        context = ' '.join(retrieved_docs)
        response = self.generate(context)
        return response, retrieved_docs

if __name__ == "__main__":
    documents = [
        "The quick brown fox jumps over the lazy dog",
        "A fox fled from danger in the forest",
        "Dogs are loyal and friendly pets",
        "The forest is full of wild animals",
        "Quick foxes climb steep hills"
    ]
    rag = SimpleRAG(documents)
    query = "fox in forest"
    response, retrieved = rag.forward(query)
    print("Query:", query)
    print("Retrieved documents:", retrieved)
    print("Generated response:", response)